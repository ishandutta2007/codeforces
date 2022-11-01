#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb push_back
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
typedef long long ll;
typedef long double ld;
using namespace std;
vector<ll> ans;
ll mod = 1000000007, p = 239;
ll n, m, a[26], p1[200010], p2[200010], h1 = 0, kk = 0, p11[200010];
vector<ll> hs(200010, 0), pos;
string s, t;
ll has(int l, int r){
  return ((hs[r] - hs[l] * p11[r - l])%mod+mod)%mod;
}
int main(){
    //freopen("s.in", "r", stdin);
    cin >> n >> m >> s >> t;
    hs[0] = 0;
    for(int i = m - 1; i >= 0; i--){
        p1[i] = max((ll)0, a[t[i] - 'a'] - i);
        a[t[i] - 'a'] = i;
    }
    for(int i = 0; i < m; i++){
        h1 = (h1 * p + p1[i]) % mod;
        if(p1[i] == 0)pos.push_back(i);
    }
    p11[0] = 1;bool ok;
    forn(i, 26)a[i] = 0;
    for(int i = n - 1; i >= 0; i--){
        p2[i] = max((ll)0, a[s[i] - 'a'] - i);
        a[s[i] - 'a'] = i;
    }
    for(int i = 0; i < n; i++){
        p11[i + 1] = (p11[i] * p) % mod;
        hs[i + 1] = (hs[i] * p + p2[i]) % mod;
    }
    for(int i = 0; i <= n - m; i++){
        ll p22 = has(i, i + m);
        forn(j, sz(pos)){
          p22 = ((p22 - p2[pos[j] + i] * p11[m - pos[j] - 1]) % mod + mod)%mod;
        }
        if(p22 == h1){
          vector<int> k(27, 0);ok = true;
          forn(j, sz(pos)){
            ll q1 = t[pos[j]] - 'a' + 1, q2 = s[i + pos[j]] - 'a' + 1;
            if((k[q1] && k[q1] != q2) || (k[q2] && k[q2] != q1)){
               ok = false;
            }k[q1] = q2; k[q2] = q1;
          }
          if(ok)ans.push_back(i + 1);
        }
    }
    cout << (int)sz(ans) << "\n";
    forn(i, sz(ans))cout << ans[i] << " ";
    return 0;
}