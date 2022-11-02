/*input
4 6
1 2
2 3
3 4
1 2
1 2
2 2
1 3
2 2
2 2
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , m , res[MAX];
vector<int> v[MAX];
void DFS(int now , int fa , int pre){
	res[now] = pre;
	for(auto to : v[now]) if(to != fa){
		DFS(to , now , min(pre , to));
	}
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 2 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	int preans = 0 , root;
	cin >> root >> root , root = (root + preans) % n + 1;
	DFS(root , root , root);
	int ans = root;
	REP(i , 2 , m + 1){
		int a , b;
		cin >> a >> b , b = (b + preans) % n + 1;
		if(a == 1) ans = min(ans , res[b]);
		if(a == 2) preans = min(ans , res[b]) , cout << preans << endl;
	}
    return 0;
}