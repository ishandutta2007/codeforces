/*input
5
90 108
45 105
75 40
165 175
33 30
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
#define MAX 160000
#define INF 0x3f3f3f3f

int n , x[MAX][2];
set<int> cc;
void solve(int now){

	REP(i , 2 , now + 1){
		if(i * i > now) break;
		while(now % i == 0){
			now /= i;
			cc.insert(i);
		}
	}
	if(now != 1) cc.insert(now);
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];
	solve(x[1][0]);
	solve(x[1][1]);
	for(auto to : cc){
		int ok = 1;
		REP(i , 1 , n + 1){
			if(x[i][0] % to != 0 && x[i][1] % to != 0) ok = 0;
		}
		if(ok == 1) return cout << to << endl , 0;
	}
	cout << -1 << endl;
    return 0;
}