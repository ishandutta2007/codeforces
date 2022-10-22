#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 300010;
const int INF = 1000000007;
const double PI = acos(-1.0);


struct BIT {
    long long x[MAXN];

    void add(int a, int b) {
        for (int i = a; i < MAXN; i += (i & (-i))) x[i] += b;
    }

    long long query(int a) {
        long long ans = 0;
        for (int i = a; i > 0; i -= (i & (-i))) ans += x[i];
        return ans;
    }
};


BIT T;
int f[1000100];
int x[MAXN], y[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 1; i <= 1000000; ++i) {
        for (int j = i; j <= 1000000; j += i) ++f[j];
    }
    
    int N, M;
    cin >> N >> M;
    set<int> S;
    for (int i = 1; i <= N; ++i) {
        cin >> x[i];
        T.add(i, x[i]);
        if (x[i] != 1) S.insert(i);
    }
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 2) {
            cout << T.query(c) - T.query(b - 1) << endl;
        } else {
            auto iter = S.lower_bound(b);
            while (iter != S.end()) {
                if (*iter > c) break;
                int k = x[*iter];
                x[*iter] = f[k];
                T.add(*iter, x[*iter] - k);
                if (x[*iter] <= 2) {
                    k = *iter + 1;
                    S.erase(iter);
                    iter = S.lower_bound(k);
                    
                } else {
                    ++iter;
                }
            }
        }
    }

    return 0;
}