/*input
4 1
2 3 4 1
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
#define MAX 300900
#define INF 0x3f3f3f3f

int n , k , x[MAX] , dp[MAX] , pre[MAX];
int query(int l , int r){
	if(l > r) return 0;
	if(l == 0) return pre[r];
	if(l != 0) return pre[r] - pre[l - 1];
}
int judge(int lim){
	int pos = 1;
	dp[0] = pre[0] = 1;
	REP(i , 1 , n + 1){
		while(x[i] - x[pos] > lim) pos ++;
		if(i < k) dp[i] = 0;
		else dp[i] = (query(pos - 1 , i - k) != 0);
		pre[i] = pre[i - 1] + dp[i];
	}
	return dp[n];
}
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	sort(x + 1 , x + 1 + n);
	int ans = -1;
	RREP(i , 40 , 0){
		int to = (ans + (1LL << i));
		if(judge(to) == 0) ans = to;
	}
	cout << ans + 1 << endl;
    return 0;
}