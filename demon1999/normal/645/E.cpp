#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <cassert>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;

struct T { int x, y; };
T t = {1, 2};
const ll mod = 1000000007;

ll dp[2000001], ss[2000001], n, m, lst[26], k;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    //freopen(".out", "w", stdout);
    dp[0] = 1; ss[0] = 1;
    cin >> n >> k;
    string s;
    cin >> s;
    forn (i, sz(s)) {
        dp[i + 1] = ss[i];
        if (lst[s[i] - 'a'] != 0) dp[i + 1] -= ss[lst[s[i] - 'a'] - 1];
        dp[i + 1] = (dp[i + 1] % mod + mod) % mod;
        ss[i + 1] = (ss[i] + dp[i + 1]) % mod;
        lst[s[i] - 'a'] = i + 1;
    }
    for (int i = sz(s); i < sz(s) + n; i++) {
        int j = 0;
        forn (nu, k)
            if (lst[nu] < lst[j]) j = nu;
        dp[i + 1] = ss[i];
        if (lst[j] != 0) {
            dp[i + 1] -= ss[lst[j] - 1];
        }
        dp[i + 1] = (dp[i + 1] % mod + mod) % mod;
        ss[i + 1] = (ss[i] + dp[i + 1]) % mod;
        lst[j] = i + 1;
    }
    cout << ss[sz(s) + n];
    return 0;
}