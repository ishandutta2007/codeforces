#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 40
#define INF 0x3f3f3f3f

int n , a , b , x[MAX] , ans = INF , cnt = 0;
vector<int> ttt;
vector<int> ff;
void DFS(int now){
	if(cnt > ans) return;
	if(now == n - 1){
		if(x[now] < 0){
			if(cnt < ans){
				ans = cnt;
				ff = ttt;
			}
		}
		else {
			int tmp = 0;
			while(x[now] >= 0) x[now] -= a , tmp ++;
			if(cnt + tmp < ans){
				ans = cnt + tmp;
				ff = ttt;
			}
			REP(i , 0 , tmp) x[now] += a;
		}
	}
	else {
		if(x[now] < 0) DFS(now + 1);
		else {
			int to = (x[now] + 1) / b + 1;
			REP(i , 0 , to + 1){
				x[now] -= b * i , x[now + 1] -= a * i , x[now + 2] -= b * i;
				cnt += i;
				REP(j , 0 , i) ttt.pb(now + 1);
				int tmp = 0;
				while(x[now] >= 0){
					ttt.pb(now);
					x[now] -= a , x[now + 1] -= b , tmp ++ , cnt ++;
				}
				DFS(now + 1);
				REP(j , 0 , tmp) ttt.pop_back();
				x[now] += a * tmp , x[now + 1] += b * tmp , cnt -= tmp;
				REP(j , 0 , i) ttt.pop_back();
				x[now] += b * i , x[now + 1] += a * i , x[now + 2] += b * i;
				cnt -= i;
			}
		}
	}
}
int32_t main(){
	cin >> n >> a >> b;
	REP(i , 1 , n + 1) cin >> x[i];
	int res = 0 , q = 0 , w = 0;
	while(x[1] >= 0) x[1] -= b , x[3] -= b , x[2] -= a , res ++ , q++;
	while(x[n] >= 0) x[n] -= b , x[n - 2] -= b , x[n - 1] -= a , res ++ , w++;
	// REP(i , 1 , n + 1) cout << x[i] << " " ; cout << endl;
	DFS(2);
	// REP(i , 1 , n + 1) cout << x[i] << " " ; cout << endl;
	cout << ans + res << endl;
	REP(i , 0 , q) ff.pb(2);
	REP(i , 0 , w) ff.pb(n - 1);
	for(auto to : ff) cout << to << " " ; cout << endl;
    return 0;
}