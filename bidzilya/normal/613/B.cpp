#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

struct TBox {
    long long Skill;
    int Id;
};

bool operator < (const TBox& lhs, const TBox& rhs) {
    return lhs.Skill > rhs.Skill;
}

int n;
long long maxA, cf, cm;
long long m;
vector<TBox> a;
vector<long long> sa;

long long GetSum(int l, int r) {
    if (l == 0) {
        return sa[r];
    } else {
        return sa[r] - sa[l - 1];
    }
}

long long FormResult(int leftCount, vector<long long>* newSkills) {
    long long completeCost = 0;
    if (leftCount > 0) {
        completeCost = 1LL * maxA * leftCount - GetSum(0, leftCount - 1);
    }

    if (completeCost > m) {
        return -1;
    }

    long long rm = m - completeCost;

    if (newSkills != nullptr) {
        for (int i = 0; i < leftCount; ++i) {
            (*newSkills)[i] = maxA;
        }
    }

    int pos = n - 1;
    int bl = leftCount;
    int br = n - 2;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        long long curMinCost = 1LL * (n - bm) * a[bm].Skill - GetSum(bm, n - 1);

        if (curMinCost <= rm) {
            pos = bm;
            br = bm - 1;
        } else {
            bl = bm + 1;
        }
    }

    if (newSkills != nullptr) {
        for (int i = leftCount; i < pos; ++i) {
            (*newSkills)[i] = a[i].Skill;
        }
        for (int i = pos; i < n; ++i) {
            (*newSkills)[i] = a[pos].Skill;
        }
    }

    rm -= 1LL * (n - pos) * a[pos].Skill - GetSum(pos, n - 1);

    long long fullInc = rm / (n - pos);

    if (newSkills != nullptr) {
        for (int i = pos; i < n; ++i) {
            (*newSkills)[i] += fullInc;
        }
    }

    long long result = 1LL * cf * leftCount + 1LL * cm * (a[pos].Skill + fullInc);

    return result;
}

int main() {
    scanf("%d" LLD_SPEC LLD_SPEC LLD_SPEC LLD_SPEC, &n, &maxA, &cf, &cm, &m);

    long long needFull = 0;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf(LLD_SPEC, &a[i].Skill);
        a[i].Id = i;

        needFull += maxA - a[i].Skill;
    }

    if (needFull <= m) {
        printf(LLD_SPEC "\n", 1LL * n * cf + 1LL * cm * maxA);
        for (int i = 0; i < n; ++i) {
            printf(LLD_SPEC " ", maxA);
        }
        printf("\n");
        return 0;
    }

    sort(a.begin(), a.end());

    sa.resize(n);
    sa[0] = a[0].Skill;
    for (int i = 1; i < n; ++i) {
        sa[i] = sa[i - 1] + a[i].Skill;
    }

    int resultLeftCount = -1;
    long long result;
    for (int i = 0; i < n; ++i) {
        long long curResult = FormResult(i, nullptr);

        if (curResult == -1) {
            continue;
        }

        if (resultLeftCount == -1 || curResult > result) {
            resultLeftCount = i;
            result = curResult;
        }
    }

    printf(LLD_SPEC "\n", result);

    vector<long long> permSkills(n);
    FormResult(resultLeftCount, &permSkills);

    vector<long long> resultSkills(n);
    for (int i = 0; i < n; ++i) {
        resultSkills[a[i].Id] = permSkills[i];
    }

    for (int i = 0; i < n; ++i) {
        printf(LLD_SPEC " ", resultSkills[i]);
    }
    printf("\n");

    return 0;
}