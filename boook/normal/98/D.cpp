/*input
4
3 3 1 1
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
#define MAX 30
#define INF 0x3f3f3f3f

int n;
int x[MAX];
vector<PII> ans;
int move(int a , int b , int t){
	REP(i , 0 , t) ans.pb(a , b);
}
void solve(int a , int b , int c , int idx , int re){
	// cout << a << " "; DB4(b , c , idx , re);
	int to = idx , cnt = 1;
	while(to + 1 <= n && x[to + 1] == x[idx]) to ++ , cnt ++;
	if(to == n){
		if(re == 1) 
			 move(a , c , cnt);
		else move(a , b , cnt - 1), 
			 move(a , c , 1), 
			 move(b , c , cnt - 1);
	}
	else {
		if(re == 1){
			solve(a , c , b , to + 1 , 1);
			move(a , c , cnt);
			solve(b , a , c , to + 1 , 1);
		}
		else if(cnt == 1){
			solve(a , c , b , to + 1 , 1);
			move(a , c , cnt);
			solve(b , a , c , to + 1 , 1);
		}
		else{
			solve(a , b , c , to + 1 , 1);
			move(a , b , cnt);
			solve(c , b , a , to + 1 , 1);
			move(b , c , cnt);
			solve(a , b , c , to + 1 , 0);
		}
	}
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	solve(1 , 2 , 3 , 1 , 0);
	cout << ans.size() << endl;
	for(auto to : ans) cout << to.A << " " << to.B << endl;
    return 0;
}