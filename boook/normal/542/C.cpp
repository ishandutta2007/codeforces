/*input
3
2 3 1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 500
#define INF 0x3f3f3f3f

int n , x[MAX] , u[MAX] , d[MAX];

int DP(int now){
	if(d[now] != d[0]) return d[now];
	else return d[now] = DP(x[now]) + 1;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	memset(d , INF , sizeof d);
	REP(i , 1 , n + 1){
		memset(u , 0 , sizeof u);
		int now = i , idx;
		while(u[now] == 0) u[now] = 1 , now = x[now];
		idx = now;
		do { d[now] = 0 , now = x[now]; } while(now != idx);
	}
	int ans = 1;
	REP(i , 1 , n + 1){
		if(d[i] == 0){
			int now = i , cnt = 0;
			do { cnt ++ , now = x[now]; } while(now != i);
			ans = ans / __gcd(cnt , ans) * cnt;
		}
		else d[i] = DP(i);
	}
	int big = 0 , final = ans;
	REP(i , 1 , n + 1) big = max(big , d[i]);
	while(final < big) final += ans;
	cout << final << endl;
    return 0;
}