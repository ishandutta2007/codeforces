/*input
3 2
1 2
3 2
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , use[MAX] , id[MAX] , e[MAX][2] , ok[MAX];
vector<int> v[MAX] , p;
void DFS(int now){
	if(use[now]) return;
	use[now] = 1;
	for(auto to : v[now]) DFS(to);
	p.pb(now);
}
int32_t main(){
	cin >> n >> m;
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		e[i][0] = a , e[i][1] = b;
	}
	REP(i , 1 , n + 1){
		DFS(i);
	}
	REP(i , 0 , p.size()) id[p[i]] = n - i;
	int cnt = 0;
	REP(i , 1 , m + 1){
		int from = e[i][0] , to = e[i][1];
		if(id[from] + 1 == id[to] && ok[from] == 0){
			ok[from] = 1;
			cnt ++;
		}
		if(cnt == n - 1){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
    return 0;
}