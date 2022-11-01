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

#define forn(i, n) for (int i = 0; i < int(n); i++)
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

struct T { ll m1, m2; };

const ll mod = 1000000007, t = 239;
ll qq1, qq2, n, m, pos1, pos2, k, l, r, a[5001][5001];
string s;
vector<ll> hs, p;


int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("round.in", "r",  stdin);
    cin >> n >> s;
    p.push_back(1);
    hs.push_back(0);
    a[0][0] = 1;
    forn (i, n) {
        a[0][i + 1] = 1;
        p.push_back(p[i] * t % mod);
        hs.push_back((hs[i] * t + s[i]) % mod);
    }
    ll mid;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (s[i - j] == '0') {
                a[i][j] = a[i][j - 1];
                continue;
            }
            k = j - 1;
            if (i - 2 * j >= 0) {
                pos1 = i - 2 * j;
                pos2 = i - j;
                l = 0;
                r = j;
                while (r - l > 1) {
                    mid = (l + r) / 2;
                    qq1 = (hs[pos1 + mid] - hs[pos1] * p[mid]) % mod;
                    if (qq1 < 0) qq1 += mod;
                    qq2 = (hs[pos2 + mid] - hs[pos2] * p[mid]) % mod;
                    if (qq2 < 0) qq2 += mod;
                    if (qq1 == qq2)
                        l = mid;
                    else
                        r = mid;
                }
                if (s[pos2 + l] > s[pos1 + l]) k++;
            }
            a[i][j] = (a[i][j - 1] + a[i - j][k]) % mod;
        }
        for (int j = i + 1; j <= n; j++)
            a[i][j] = a[i][j - 1];
    }
    cout << a[n][n];
    return 0;
}