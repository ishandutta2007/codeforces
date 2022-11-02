/*input
1000000
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
#define MAX 
#define INF 0x3f3f3f3f

vector<int> DFS(int now){
    if(now == 1) return vector<int>{1};
    if(now == 2) return vector<int>{1 , 2};
    if(now == 3) return vector<int>{1 , 1 , 3};
    else {
        vector<int> ans;
        for(int i = 1 ; i <= now ; i += 2) ans.pb(1);
        vector<int> G = DFS(now / 2);
        for(auto to : G) ans.pb(to * 2);
        return ans;
    }
}
int n;
int32_t main(){
    IOS;
    cin >> n;
    vector<int> ans = DFS(n);
    for(auto to : ans) cout << to << " " ; cout << endl;
    return 0;
}