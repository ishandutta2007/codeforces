/*input
10
2 8 6 1 2 7 6 9 2 8
4 9 4 3 5 2 9 3 7 3
1 8
2 8
3 8
4 10
5 1
6 4
7 3
8 10
9 2
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
// #define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX] , have = 0 , need = 0;
vector<PII> v[MAX];
void DFS(int now , int fa , int val){
	for(auto to : v[now]) DFS(to.A , now , to.B);
	if(a[now] < b[now]){
		if(now == 1){
			cout << "NO" << endl;
			exit(0);
		}
		else {
			int v1 = b[now] - a[now];
			if(val > 1 && (have - need + 1) / v1 / (val - 1) == 0){
				cout << "NO" << endl;
				exit(0);
			}
			a[fa] -= v1 * val , a[now] = b[now];
			have -= v1 * (val - 1);
		}
	}
	if(a[now] > b[now]){
		int v1 = a[now] - b[now];
		a[fa] += a[now] - b[now] , a[now] = b[now];
	}
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) cin >> b[i];
	REP(i , 1 , n + 1) have += a[i];
	REP(i , 1 , n + 1) need += b[i];
	REP(i , 2 , n + 1){
		int p , x;
		cin >> p >> x;
		v[p].pb(mp(i , x));
	}
	DFS(1 , 1 , 1);
	cout << "YES" << endl;
    return 0;
}