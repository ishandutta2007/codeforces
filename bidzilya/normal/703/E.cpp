#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

using TFact = vector<pair<long long, int>>;

TFact GetFact(long long x) {
    vector<pair<long long, int>> result;
    for (int i = 2; 1LL * i * i <= x; ++i) {
        if (x % i == 0) {
            result.push_back(make_pair(i, 0));
            while (x % i == 0) {
                ++result.back().second;
                x /= i;
            }
        }
    }
    if (x > 1) {
        result.push_back(make_pair(x, 1));
    }
    return result;
}

template<typename TDoOnDel>
void EnumerateDels(const TFact& fact, int pos, long long cur, TDoOnDel func) {
    if (pos == fact.size()) {
        func(cur);
    } else {
        for (int i = 0; i <= fact[pos].second; ++i) {
            if (i > 0) {
                cur *= fact[pos].first;
            }
            EnumerateDels(fact, pos + 1, cur, func);
        }
    }
}

int main() {
    int n;
    long long k;
    scanf("%d" LLD_SPEC, &n, &k);

    TFact kf = GetFact(k);

    vector<TFact> a(n);
    vector<long long> aValue(n);
    for (int i = 0; i < n; ++i) {
        long long x;
        scanf(LLD_SPEC, &x);

        aValue[i] = x;

        a[i].resize(kf.size());
        for (int j = 0; j < (int) kf.size(); ++j) {
            a[i][j].first = kf[j].first;
            a[i][j].second = 0;

            while (x % a[i][j].first == 0) {
                ++a[i][j].second;
                x /= a[i][j].first;
            }
        }
    }

    if (k == 1) {
        auto itr = min_element(aValue.begin(), aValue.end());

        printf("1\n%d\n", static_cast<int>(itr - aValue.begin() + 1));
        return 0;
    }

    vector<long long> dels;
    EnumerateDels(kf, 0, 1, [&dels] (long long del) {
        dels.push_back(del);
    });
    const int dc = dels.size();

    map<long long, int> revId;
    for (int i = 0; i < dc; ++i) {
        revId[dels[i]] = i;
    }

    vector<vector<int>> nxt(dc, vector<int>(kf.size()));
    for (int i = 0; i < dc; ++i) {
        for (int j = 0; j < (int) kf.size(); ++j) {
            long long nxtValue = dels[i];

            if ((k / dels[i]) % kf[j].first == 0) {
                nxtValue *= kf[j].first;
                nxt[i][j] = revId[nxtValue];
            } else {
                nxt[i][j] = i;
            }
        }
    }

    vector<vector<pair<int, long long>>> result(n + 1, vector<pair<int, long long>>(dc, make_pair(-1, -1)));
    vector<vector<int>> pr(n + 1, vector<int>(dc, -1));

    const int oid = revId[1];

    result[0][oid].first = 0;
    result[0][oid].second = 0;

    for (int i = 0; i < n; ++i) {
        result[i + 1] = result[i];
        for (int j = 0; j < dc; ++j) {
            if (result[i + 1][j].first != -1) {
                pr[i + 1][j] = j;
            }
        }
        for (int di = 0; di < dc; ++di) {
            if (result[i][di].first != -1) {
                int newDi = di;
                for (int j = 0; j < (int) kf.size(); ++j) {
                    for (int t = 0; t < a[i][j].second; ++t) {
                        newDi = nxt[newDi][j];
                    }
                }
                if (result[i + 1][newDi].first == -1 || 
                    result[i + 1][newDi].first > result[i][di].first + 1 ||
                    (result[i + 1][newDi].first == result[i][di].first + 1 &&
                     result[i + 1][newDi].second > result[i][di].second + aValue[i]))
                {
                    result[i + 1][newDi].first = result[i][di].first + 1;
                    result[i + 1][newDi].second = result[i][di].second + aValue[i];
                    pr[i + 1][newDi] = di;
                }
            }
        }
    }

    const int kid = revId[k];

    if (result[n][kid].first == -1) {
        printf("-1\n");
    } else {
        vector<int> seq;
        for (int i = n, j = kid; i > 0; j = pr[i][j], --i) {
            if (pr[i][j] != j) {
                seq.push_back(i);
            }
        }
        sort(seq.begin(), seq.end());
        printf("%d\n", (int) seq.size());
        for (int x : seq) {
            printf("%d ", x);
        }
        printf("\n");
    }

    return 0;
}