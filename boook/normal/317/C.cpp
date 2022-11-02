/*input
6 1 4
0 1 0 1 0 1
1 0 1 0 1 0
1 2
4 3
4 5
4 6
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 330
#define INF 0x3f3f3f3f

int n , m , all , a[MAX] , b[MAX];
int dis[MAX][MAX];
vector<int> v1 , v2 , v3;
void ADDE(int from , int to , int val){
	v1.pb(from) , v2.pb(to) , v3.pb(val);
}
void solve(int from , int to , int val){
	if(dis[from][to] == 1) ADDE(from , to , val);
	else {
		int nxt = -1;
		REP(i , 1 , n + 1) if(dis[from][i] == 1 && dis[from][to] == dis[i][to] + 1) nxt = i;
		if(a[nxt] >= val){
			solve(nxt , to , val);
			ADDE(from , nxt , val);
		}
		else if(a[nxt] + val > all){
			ADDE(from , nxt , all - a[nxt]);
			solve(nxt , to , val);
			ADDE(from , nxt , val - (all - a[nxt]));
		}
		else {
			ADDE(from , nxt , val);
			solve(nxt , to , val);
		}
	}
}
int32_t main(){
	IOS;
	cin >> n >> all >> m;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) cin >> b[i];
	REP(i , 1 , n + 1) REP(j , 1 , n + 1) dis[i][j] = INF;
	REP(i , 1 , n + 1) dis[i][i] = 0;
	REP(i , 1 , m + 1){
		int aa , bb;
		cin >> aa >> bb;
		dis[aa][bb] = 1;
		dis[bb][aa] = 1;
	} 
	REP(k , 1 , n + 1) REP(i , 1 , n + 1) REP(j , 1 , n + 1)
		dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);

	REP(i , 1 , n + 1) REP(j , 1 , n + 1){
		if(dis[i][j] != INF && a[i] > b[i] && a[j] < b[j]){
			int val = min(a[i] - b[i] , b[j] - a[j]);
			solve(i , j , val);
			a[i] -= val , a[j] += val;
		}
	}
	REP(i , 1 , n + 1) if(a[i] != b[i]) return cout << "NO" << endl , 0;

	cout << v1.size() << endl;
	REP(i , 0 , v1.size()) cout << v1[i] << " " << v2[i] << " " << v3[i] << endl;
    return 0;
}