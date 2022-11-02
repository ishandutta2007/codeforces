/*input
7
1 1 1 1 1 1 1
2 2 2 3 6 7 6
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX] , use[MAX] , idx[MAX];
vector<int> v[MAX];
void DFS(int now){
	if(use[now]) return;
	use[now] = 1;
	for(auto to : v[now]) DFS(to);
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) cin >> b[i] , v[i].pb(b[i]) , v[b[i]].pb(i);
	int ans = 0;
	REP(i , 1 , n + 1) if(use[i] == 0){
		DFS(i);
		int now = i;
		while(idx[now] == 0){
			idx[now] = 1;
			now = b[now];
		}
		int sml = a[now] , ss = now;
		now = b[now];
		while(now != ss) sml = min(sml , a[now]) , now = b[now];
		ans += sml;
	}
	cout << ans << endl;
    return 0;
}