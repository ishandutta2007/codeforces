/*input
5 6
1 2
2 3
3 5
1 4
4 5
1 3
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
#define MAX 5050
#define INF 0x3f3f3f3f

int n , m , e[MAX][2] , use[MAX] , dis[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 0 , m) REP(j , 0 , 2) cin >> e[i][j];
	use[1] = 1 , use[n] = 2;
	REP(j , 0 , n) REP(i , 0 , m){
		if(use[e[i][0]] & 1) use[e[i][1]] |= 1;
		if(use[e[i][1]] & 2) use[e[i][0]] |= 2;
	}
	MEM(dis , INF);
	REP(j , 0 , n) REP(i , 0 , m){
		if(use[e[i][0]] == 3 && use[e[i][1]] == 3){
			dis[e[i][1]] = min(dis[e[i][1]] , dis[e[i][0]] + 2);
			dis[e[i][0]] = min(dis[e[i][0]] , dis[e[i][1]] - 1);
		}
	}
	REP(i , 0 , m){
		if(use[e[i][0]] == 3 && use[e[i][1]] == 3){
			int val = dis[e[i][1]] - dis[e[i][0]];
			if(1 <= val && val <= 2);
			else return cout << "No" << endl , 0;
		}
	}
	cout << "Yes" << endl;
	REP(i , 0 , m){
		if(use[e[i][0]] == 3 && use[e[i][1]] == 3)
			cout << dis[e[i][1]] - dis[e[i][0]] << endl;
		else cout << 1 << endl;
	}
    return 0;
}