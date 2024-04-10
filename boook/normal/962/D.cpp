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
#define int int_fast64_t
#define MAX 200500
#define INF 0x3f3f3f3f

int n , x[MAX] , ans[MAX];
map<int , vector<int>> cc;
int32_t main(){
    IOS;
   	cin >> n;
   	REP(i , 1 , n + 1) cin >> x[i];
   	REP(i , 1 , n + 1) cc[x[i]].pb(i);
    
    auto now = cc.begin();
    while(now != cc.end()){
    	vector<int> sol = (*now).B;
    	int val = (*now).A;
    	// DBGG("val = " , val);
    	// for(auto to : sol) cout << to << " ";cout << endl;
    	cc.erase(now);
    	sort(ALL(sol));
    	if(sol.size() % 2 == 1){
    		ans[sol.back()] = val;
    		sol.pop_back();
    	}
    	for(int i = 1 ; i < sol.size() ; i += 2) cc[val + val].pb(sol[i]);
    	now = cc.begin();
    }

    int cnt = 0;
    REP(i , 1 , n + 1) if(ans[i] != 0) cnt ++;
    cout << cnt << endl;
    REP(i , 1 , n + 1) if(ans[i] != 0) cout << ans[i] << " "; cout << endl;
    return 0;
}