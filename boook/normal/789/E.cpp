/*input
50 2
100 25
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
#define MAX 2020
#define INF 0x3f3f3f3f
#define N 1000

int n , k , in , x[MAX] , dp[MAX] , dis[MAX];
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , k + 1) cin >> in , x[in] = 1;

	queue<int> qu;
	REP(i , 0 , MAX) dis[i] = INF;
	REP(i , 0 , N + 1) if(x[i]) dis[i - n + N] = 1 , qu.push(i - n + N);

	while(qu.size()){
		int now = qu.front(); qu.pop();
		REP(i , 0 , N + 1) if(x[i]){
			int to = now + i - n;
			if(to >= 0 && to < MAX && dis[to] > dis[now] + 1){
				dis[to] = dis[now] + 1;
				qu.push(to);
			}
		}
	}
	if(dis[N] == INF) cout << -1 << endl;
	else cout << dis[N] << endl;
    return 0;
}