/*input
8
6 2 3
3 4 5
12 6 7
1 -1 8
4 -1 -1
5 -1 -1
14 -1 -1
2 -1 -1
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
#define MAX 109000
#define INF 0x3f3f3f3f

int n , v[MAX] , ls[MAX] , rs[MAX] , ok[MAX] , ans;
multiset<int> sml , big;
set<int> good;
void solve(int now){
	if(now == 0) return ;
	int ok = 1;
	if(sml.size()){
		auto tmp = sml.end(); tmp --;
		if((*tmp) <= v[now]);
		else ok = 0;
	}
	if(big.size()){
		auto tmp = big.begin();
		if((*tmp) >= v[now]);
		else ok = 0;
	}
	if(ok == 1) good.insert(v[now]);
	big.insert(v[now]);
	solve(ls[now]);
	big.erase(big.find(v[now]));

	sml.insert(v[now]);
	solve(rs[now]);
	sml.erase(sml.find(v[now]));
}
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1){
		cin >> v[i] >> ls[i] >> rs[i];
		ok[ls[i]] = 1;
		ok[rs[i]] = 1;
		ls[i] = max(ls[i] , 0);
		rs[i] = max(rs[i] , 0);
	}
	REP(i , 1 , n + 1){
		if(ok[i] == 0) solve(i);
	}
	REP(i , 1 , n + 1) if(good.find(v[i]) == good.end()) ans ++;
	cout << ans << endl;
    return 0;
}