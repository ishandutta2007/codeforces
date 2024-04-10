/*input
4 3
3 10
2 7
2 8
1 1
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 300900
#define INF 0x3f3f3f3f

vector<int> one , two , three;
int n , m , dp[MAX];
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1){
        int w , v;
        cin >> w >> v;
        if(w == 1) one.pb(v);
        if(w == 2) two.pb(v);
        if(w == 3) three.pb(v);
    }
    sort(ALL(one) , greater<int>());
    sort(ALL(three) , greater<int>());
    vector<int> tmp;
    for(int i = 1 ; i < one.size() ; i += 2) tmp.pb(one[i] + one[i - 1]);
    for(int i = 0 ; i < two.size() ; i += 1) tmp.pb(two[i]);

    sort(ALL(tmp) , greater<int>());
    REP(i , 1 , tmp.size()) tmp[i] += tmp[i - 1];
    REP(i , 0 , tmp.size()) dp[(i + 1) * 2] = tmp[i];

    tmp.clear();
    for(int i = 2 ; i < one.size() ; i += 2) tmp.pb(one[i] + one[i - 1]);
    for(int i = 0 ; i < two.size() ; i += 1) tmp.pb(two[i]);
    sort(ALL(tmp) , greater<int>());
    if(one.size() && tmp.size()) tmp[0] += one[0];
    if(one.size()) dp[1] = one[0];
    REP(i , 1 , tmp.size()) tmp[i] += tmp[i - 1];
    REP(i , 0 , tmp.size()) dp[(i + 1) * 2 + 1] = tmp[i];

    REP(i , 1 , m + 1) dp[i] = max(dp[i] , dp[i - 1]);

    // REP(i , 1 , m + 1) cout << dp[i] << " " ; cout << endl;
    REP(i , 1 , three.size()) three[i] += three[i - 1];
    int ans = dp[m];
    REP(i , 0 , three.size()){
        int have = m - (i + 1) * 3;
        if(have >= 0){
            ans = max(ans , three[i] + dp[have]);
        }
    }
    cout << ans << endl;
    return 0;
}