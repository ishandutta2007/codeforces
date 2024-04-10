#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; ++i)
#define REPNM(i,j,k)   for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define endl "\n"
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
#define MAX 100090
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)

int ls[MAX * 51] , rs[MAX * 51];
PII b[MAX * 51];
int N = 1000000000000090LL;
int n , d , x[MAX] , po = 2 , dp[MAX] , pa[MAX];
void update(int now , int l , int r , int k , int val , int index){
	// DB4("now = " , now , "k = " , k);
	if(l == k && r == k) { b[now] = mp(val , index); return; }
	if(k <= mid){
		if(ls[now] == 0) ls[now] = po++;
		update(ls[now] , l , mid , k , val , index);
	}
	if(mid + 1 <= k){
		if(rs[now] == 0) rs[now] = po++;
		update(rs[now] , mid + 1 , r , k , val , index);
	}
	b[now] = max(b[ls[now]] , b[rs[now]]);
}
PII query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return b[now];
	if(qr <= mid){
		if(ls[now] == 0) return mp(0 , -1);
		return query(ls[now] , l , mid , ql , qr);
	}
	if(mid + 1 <= ql){
		if(rs[now] == 0) return mp(0 , -1);
		return query(rs[now] , mid + 1 , r , ql , qr);
	}
	PII ans = mp(0 , -1);
	if(ls[now]) ans = max(ans , query(ls[now] , l , mid , ql , qr));
	if(rs[now]) ans = max(ans , query(rs[now] , mid + 1 , r , ql , qr));
	return ans;
}
int32_t main(){
	cin >> n >> d;
	REPNM(i , 1 , n + 1) cin >> x[i];
	int ans = 0;
	b[0] = b[1] = mp(0 , -1);
	REPNM(i , 1 , n + 1){
		int a = x[i] - d , b = x[i] + d;
		dp[i] = 1 , pa[i] = -1;
		PII tmp = mp(0 , -1);
		if(1 <= a) tmp = max(tmp , query(1 , 1 , N , 1 , a));
		if(b <= N) tmp = max(tmp , query(1 , 1 , N , b , N));
		// DB4(1 , a , b , N);
		dp[i] = tmp.A + 1 , pa[i] = tmp.B;
		update(1 , 1 , N , x[i] , dp[i] , i);
		// DB4("now i = " , x[i] , dp[i] , pa[i]);
		ans = max(ans , dp[i]);
	}
	RREP(i , n , 1){
		if(dp[i] == ans){
			cout << ans << endl;
			stack<int> sol;
			int now = i;
			while(true){
				sol.push(now);
				if(pa[now] == -1) break;
				else now = pa[now];
			}
			while(sol.size()) cout << sol.top() << " " , sol.pop();
			cout << endl;
			return 0;
		}
	}
    return 0;
}