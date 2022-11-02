/*input
5
30 25 20 15 10
9 10 12 4 13
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
#define int int_fast64_t
#define MAX 100900
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX] , pre[MAX];
int g[MAX] , sum[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) cin >> b[i];
	REP(i , 1 , n + 1) pre[i] = pre[i - 1] + b[i];
	REP(i , 1 , n + 1){
		if(a[i] <= b[i]) sum[i] += a[i];
		else {
			int now = i;
			RREP(j , 20 , 0){
				int to = now + (1 << j);
				if(to <= n && pre[to] - pre[i - 1] <= a[i]) now = to;
			}
			// DBGG("now = " , now);
			g[i] ++ , g[now + 1] --;
			if(now + 1 <= n) sum[now + 1] += a[i] - (pre[now] - pre[i - 1]);
		}
	}
	REP(i , 1 , n + 1) g[i] += g[i - 1];
	REP(i , 1 , n + 1) cout << g[i] * b[i] + sum[i] << " "; cout << endl;
    return 0;
}