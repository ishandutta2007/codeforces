/*input
1 42
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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mod 1000000007LL
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int sum[MAX * 4];
int update(int now , int l , int r , int k , int val){
	if(l == r) sum[now] = val;
	else {
		if(k <= mid + 0) update(ls , l , mid + 0 , k , val);
		if(mid + 1 <= k) update(rs , mid + 1 , r , k , val);
		sum[now] = (sum[ls] + sum[rs]) % mod;
	}
}
int query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return sum[now];
	else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return query(ls , l , mid + 0 , ql , qr) + query(rs , mid + 1 , r , ql , qr);
}
int n , x[MAX] , a[MAX];
vector<int> sol[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) sol[x[i]].pb(i);
	update(1 , 0 , n , 0 , 1);
	REP(i , 1 , MAX){
		int pre = 0;
		for(auto to : sol[i]){
			a[to] = query(1 , 0 , n , pre , to) * i % mod;
			// DB4("a[" , to , "] = " , a[to]);
			update(1 , 0 , n , to , a[to]);
			pre = to;
		}
	}
	cout << (sum[1] + mod - 1) % mod << endl;
    return 0;
}