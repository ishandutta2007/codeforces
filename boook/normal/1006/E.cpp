/*input
9 6
1 1 1 3 5 3 5 7
3 1
1 5
3 4
7 3
1 8
1 9
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , m , in[MAX] , son[MAX] , pos = 0;
vector<int> v[MAX] , sol;
void DFS(int now , int fa){
    in[now] = pos ++;
    son[now] = 1;
    sol.pb(now);
    for(auto to : v[now]) DFS(to , now) , son[now] += son[to];
}

int32_t main(){
	IOS;
	cin >> n >> m;
	int val;
	REP(i , 2 , n + 1) cin >> val , v[val].pb(i);
	REP(i , 1 , n + 1) sort(ALL(v[i]));
	DFS(1 , 0);
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		if(son[a] < b) cout << -1 << endl;
		else cout << sol[in[a] + b - 1] << endl;
	}
    return 0;
}