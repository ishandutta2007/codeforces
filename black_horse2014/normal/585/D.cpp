#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef long double DB;
#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define counti(x) (__builtin_popcount(x))
#define clz(x) (__builtin_clz(x))
#define ctz(x) (__builtin_ctz(x))
#define countl(x) (__builtin_popcountll(x))
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define Error(x) cout << #x << " = " << endl
#define X first
#define Y second
  
template <typename T, typename U> 
inline void chkmax(T& x, U y) {
    if (x < y) x = y;
}
  
template <typename T, typename U>
inline void chkmin(T& x, U y) {
    if (y < x) x = y;
}
#define MX 44
int n;
LL l[MX], m[MX], w[MX];
map<PLL, PLI> M1, M2;
int m1, m2;
void calc(int step, LL a, LL b, LL c, int state) {
    if (step == m1) {
        PLL res = PLL(b - a, c - a);
        if (M1.count(res)) {
            PLI tmp = M1[res];
            if (tmp.X < a) {
                M1[res] = PLI(a, state);
            }
        } else {
            M1[res] = PLI(a, state);
        }
        return;
    }
    calc(step + 1, a + l[step], b + m[step], c, state * 3 + 2);
    calc(step + 1, a, b + m[step], c + w[step], state * 3);
    calc(step + 1, a + l[step], b, c + w[step], state * 3 + 1);
}
void calc1(int step, LL a, LL b, LL c, int state) {
    if (step == n) {
        PLL res = PLL(b - a, c - a);
        if (M2.count(res)) {
            PLI tmp = M2[res];
            if (tmp.X < a) {
                M2[res] = PLI(a, state);
            }
        } else {
            M2[res] = PLI(a, state);
        }
        return;
    }
    calc1(step + 1, a + l[step], b + m[step], c, state * 3 + 2);
    calc1(step + 1, a, b + m[step], c + w[step], state * 3);
    calc1(step + 1, a + l[step], b, c + w[step], state * 3 + 1);
}
int cur1, cur2;
LL sum;
void solve() {
    cur1 = -1, cur2 = -1;
    sum = 1LL << 55;
    sum = -sum;
    map<PLL, PLI> :: iterator it;
    for (it = M1.begin(); it != M1.end(); it++) {
        PLL cnt = it -> first;
        PLI val = it -> second;
        cnt.X = -cnt.X, cnt.Y = -cnt.Y;
        if (!M2.count(cnt)) continue;
        
        PLI val1 = M2[cnt];
        if (sum < val.X + val1.X) {
            sum = val.X + val1.X;
            cur1 = val.Y, cur2 = val1.Y;
        }
    }
}
void Print1(int x) {
    if (x == 0) {
        puts("MW");
        return;
    }
    if (x == 1) {
        puts("LW");
        return;
    }
    if (x == 2) {
        puts("LM");
        return;
    }
    puts("OOH");
}
void Print() {
    VI cnt, cnt1;
    cnt.clear();
    for (int i = 0; i < m1; i++) {
        cnt.pb(cur1 % 3); cur1 /= 3;
    }
    reverse(all(cnt));
    cnt1.clear();
    for (int i = 0; i < m2; i++) {
        cnt1.pb(cur2 % 3);cur2 /= 3;
    }
    reverse(all(cnt1));
    for (int i = 0; i < cnt.size(); i++) Print1(cnt[i]);
    for (int i = 0; i < cnt1.size(); i++) Print1(cnt1[i]);
}
int main() {
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> m[i] >> w[i];
    }
    if (n == 1) {
        if (l[0] == m[0] && m[0] == 0) {
            puts("LM"); return 0;
        }
        if (l[0] == w[0] && w[0] == 0) {
            puts("LW"); return 0;
        }
        if (m[0] == w[0] && w[0] == 0) {
            puts("MW"); return 0;
        }
        puts("Impossible");
        return 0;
    }
    m1 = n / 2, m2 = n - m1;
    calc(0, 0, 0, 0, 0);
    calc1(m1, 0, 0, 0, 0);
    
    solve();
    if (cur1 == -1) {
        puts("Impossible");return 0;
    }
    Print();
    return 0;
}