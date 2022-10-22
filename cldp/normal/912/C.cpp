#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const long long INFF = 1LL * 100000000 * 100000000;
const double PI = acos(-1.0);

long long bounty, increase, damage;
long long mh[MAXN], sh[MAXN], re[MAXN], te[MAXN];

struct node {
    long long A, B, C;
    bool operator < (const node &T) const {
        return A < T.A;
    }
};

node X[MAXN];

long long calte(long long mh, long long sh, long long re) {
    if (sh > damage) return -1;
    if (mh <= damage) return INFF;
    if (re == 0) return INFF;
    return (damage - sh) / re;
}


int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    cin >> bounty >> increase >> damage;
    multiset<long long> S;

    for (int i = 0; i < N; ++i) {
        cin >> mh[i] >> sh[i] >> re[i];
        te[i] = calte(mh[i], sh[i], re[i]);
        if (te[i] != -1) S.insert(te[i]);
    }

    for (int i = 0; i < M; ++i) {
        cin >> X[i].A >> X[i].B >> X[i].C;
        --X[i].B;
    }
    sort(X, X + M);

    long long ans = 0;
    for (int i = 0; i < M; ) {
        int j = i;
        while (j < M && X[j].A == X[i].A) ++j;
        while (*S.begin() < X[i].A) {
            ans = max(ans, ((long long)(*S.begin()) * increase + bounty) * (long long)S.size());
           // cout << *S.begin() << " " << S.size() << endl;
            S.erase(S.begin());
        }
        ans = max(ans, ((X[i].A - 1) * increase + bounty) * (long long)S.size());
        for (int k = i; k < j; ++k) {
            long long A = X[k].A, B = X[k].B, C = X[k].C;
            sh[B] = C;
            if (S.find(te[B]) != S.end()) S.erase(S.find(te[B]));
            te[B] = A + calte(mh[B], sh[B], re[B]);
            if (te[B] != A - 1) S.insert(te[B]);
        }
        i = j;
    }
    while (!S.empty()) {
        if (*S.begin() >= INFF && increase != 0) {
            ans = -1;
            break;
        }
        ans = max(ans, ((long long)(*S.begin()) * increase + bounty) * (long long)S.size());
         //   cout << *S.begin() << " " << S.size() << endl;
        S.erase(S.begin());
    }

    cout << ans << endl;

    return 0;
}