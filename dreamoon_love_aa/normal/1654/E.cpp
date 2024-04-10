#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
const int SIZE = 100001;
const int AA = 300;
int a[SIZE], n;
LL tmp[SIZE * 1000];
int an;
void solve_small(int d) {
    int m = 0;
    for(int i = 1; i <= n; i++) {
        tmp[m++] = a[i] - (LL)i * d;
    }
    sort(tmp, tmp + m);
    for(int i = 0, j; i < m; i = j) {
        for(j = i + 1; j < m && tmp[j] == tmp[i]; j++);
        an = max(an, j - i);
    }
}
int from[2 * SIZE];
void solve_big() {
    int m = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n && AA * (j - i) <= SIZE; j++) {
            auto ret = div(a[j] - a[i], j - i);
            if(!ret.rem) {
                if(abs(ret.quot) <= AA) continue;
                tmp[m++] = (a[i] - (LL)i * ret.quot) * 1000001LL + ret.quot;
            }
        }
    }
    for(int i = 1; i * (i - 1) / 2 <= 2 * SIZE; i++) from[i * (i - 1) / 2] = i;
    sort(tmp, tmp + m);
    for(int i = 0, j; i < m; i = j) {
        for(j = i + 1; j < m && tmp[j] == tmp[i]; j++);
        an = max(an, from[j - i]);
    }
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = -AA; i <= AA; i++) {
        solve_small(i);
    }
    solve_big();
    cout << n - an << '\n';
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}