/*input
abcde
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
#define MAX 
#define INF 0x3f3f3f3f

string s;
int32_t main(){
    int ans = INF;
    IOS , cin >> s;
    REP(i , 0 , 26){
        vector<int> sol;
        sol.pb(-1);
        REP(j , 0 , s.size()){
            if(s[j] - 'a' == i) sol.pb(j);
        }
        sol.pb(s.size());
        int k = 0;
        REP(j , 1 , sol.size()){
            k = max(k , (sol[j] - 1) - (sol[j - 1] + 1) + 1 + 1);
        }
        ans = min(ans , k);
    }
    cout << ans << endl;
    return 0;
}