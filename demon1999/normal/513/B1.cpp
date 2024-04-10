#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re return
typedef long long ll;
typedef long double ld;
using namespace std;
int main(){
    ll n, m, dp[51];
    cin >> n >> m;
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++)dp[i] = dp[i - 1] * 2;
    ll la = 0;
    vector<ll> a; ll l = n - 1 ;
    for(int i = 1; i <= n && l > 0; i++){
      //cout << la << " " << l << " " << m << endl;
      while(l > 0){
        la++;
        //cout << l << " " << la << endl;
        if(m > dp[l]){
          m -= dp[l]; l--;
          a.push_back(la);
          continue;
        }
        cout << la << " ";
        l--; break;
      }
    }
    if(l == 0)cout << n << " ";
    for(int i = sz(a) -1; i >= 0; i--)cout << a[i] << " ";
    cout << endl;
    return 0;
}