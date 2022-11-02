/*input
6
aa bb aa aa bb bb
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 550
#define INF 0x3f3f3f3f
#define mod 1000000009
// #define AC 37
int n , u[550][550] , v[MAX] , x[MAX] , h[MAX][MAX]; string s[MAX]; map<string , int> cc; int32_t main(){IOS; cin >> n; srand(time(NULL)); int AC = rand() % 100 * 2 + 37; REP(i , 1 , n + 1) cin >> s[i] , v[i] = s[i].size(); REP(i , 1 , n + 1) v[i] += v[i - 1]; int pos = 1; REP(i , 1 , n + 1){if(cc.find(s[i]) == cc.end()) cc[s[i]] = pos ++; x[i] = cc[s[i]]; } REP(i , 1 , n + 1) REP(j , 1 , n + 1){h[i][j] = 0; REP(k , i , j + 1) h[i][j] = (h[i][j] * AC + x[k]) % mod; } int ans = n - 1 + v[n] , base = ans; REP(i , 1 , n + 1) REP(j , i , n + 1){int val = h[i][j] , len = j - i + 1 , cnt = 1 , po = j + 1; while(po + len - 1 <= n){if(h[po][po + len - 1] == val) po = po + len , cnt ++; else po = po + 1; } if(cnt >= 2){int las = v[j] - v[i - 1] + len - 1; int have = len; ans = min(ans , base + (have - las) * cnt); } } cout << ans << endl; return 0; }