/*input
8 4
1 3 4 5 5 3 4 1
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
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int n , m , x[MAX] , sml[MAX * 4] , dp[MAX];
void Build(int now , int l , int r){
	if(l == r) sml[now] = x[l];
	else {
		Build(ls , l , mid + 0);
		Build(rs , mid + 1 , r);
		sml[now] = min(sml[ls] , sml[rs]);
	}
}
int query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return sml[now];
	if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return min(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	Build(1 , 1 , n);
	int sum = 0;
	REP(i , 1 , n + 1) sum += x[i];
	REP(i , 1 , n + 1){
		dp[i] = dp[i - 1];
		if(i - m + 1 >= 1) dp[i] = max(dp[i] , dp[i - m] + query(1 , 1 , n , i - m + 1 , i));
	}
	cout << sum - dp[n] << endl;
    return 0;
}