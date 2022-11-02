/*input
3
1 1 2
2 3
1 3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 300900
#define INF 0x3f3f3f3f

int n , x[MAX];
vector<int> v[MAX];
int bb = 0 , rr = 0 , ans = 0;
PII DFS(int now , int fa){
	PII sum = mp(0 , 0);
	for(auto to : v[now]) if(to != fa){
		PII res = DFS(to , now);
		int lasbb = bb - res.F;
		int lasrr = rr - res.S;
		if((lasbb == 0 || lasrr == 0) && (res.F == 0 || res.S == 0)) ans ++;
		sum.F += res.F;
		sum.S += res.S;
	}
	if(x[now] == 1) sum.S ++;
	if(x[now] == 2) sum.F ++;
	return sum;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) bb += x[i] == 2;
	REP(i , 1 , n + 1) rr += x[i] == 1;
	REP(i , 2 , n + 1){
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	DFS(1 , 1);
	cout << ans << endl;
    return 0;
}