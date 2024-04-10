#ifndef ONLINE_JUDGE
        #include <iostream>
#else
        #include <bits/stdc++.h>
#endif
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const nmax = 5010;
char line[nmax];
vi pos;

ll cal(vi v) {
    FORd(i, sz(v), 0) if (v[i] == -1) {v[i - 1] = v[i - 1] * v[i + 1]; v.erase(v.begin() + i + 1); v.erase(v.begin() + i);}
    ll res = 0;
    FOR(i, 0, sz(v)) res += v[i];
    return res;
}

ll cal(char *s, int len) {
    vi v;
    FOR(i, 0, len) if (s[i] == '*') v.push_back(-1); else if (s[i] != '+') v.push_back(s[i] - '0');
    return cal(v);
}

void solve() {
     scanf("%s", line);
     int len = strlen(line);
     pos.push_back(-1);
     FOR(i, 0, len) if (line[i] == '*') pos.push_back(i);
     pos.push_back(len);
     ll ans = _I64_MIN;
     FOR(i, 0, sz(pos)) {
            vi v;
            FOR(j, 0, pos[i] + 1) if (line[j] == '*') v.push_back(-1); else if (line[j] != '+') v.push_back(line[j] - '0');
            FOR(j, i + 1, sz(pos)) {
                   vi v2 = v;
                   v2.push_back(cal(line + pos[i] + 1, pos[j] - pos[i] - 1));
                   FOR(k, pos[j], len) if (line[k] == '*') v2.push_back(-1); else if (line[k] != '+') v2.push_back(line[k] - '0');
                   ans = MAX(ans, cal(v2));
            }
     }
     printf("%I64d", ans);
}

int main() {
#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
    return 0;
}