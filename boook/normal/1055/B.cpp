/*input
4 7 3
1 2 3 4
0
1 2 3
0
1 1 3
0
1 3 1
0
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , k , x[MAX] , u[MAX] , ans;
void update(int idx){
	ans ++;
	if(u[idx + 1] == 1) ans --;
	if(u[idx - 1] == 1) ans --;
}
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	ans = 0;
	REP(i , 1 , n + 1) if(x[i] > k) u[i] = 1 , update(i);
	REP(i , 1 , m + 1){
		int type , val , idx;
		cin >> type;
		if(type == 0){
			cout << ans << endl;
		}
		if(type == 1){
			cin >> idx >> val;
			x[idx] += val;
			if(x[idx] > k && u[idx] == 0) u[idx] = 1 , update(idx);
		}
	}
    return 0;
}