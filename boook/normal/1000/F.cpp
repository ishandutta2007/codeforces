
 /*input
6
1 1 2 3 2 4
2
2 6
1 2
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
#define MAX 500090
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)

PII sml[MAX * 4];
int n , m , x[MAX] , q[MAX][2] , pre[MAX] , v[MAX] , ans[MAX];
vector<int> sol[MAX];
void update(int now , int l , int r , int k , PII val){
	if(l == r) sml[now] = val;
	else{
		if(k <= mid + 0) update(ls , l , mid + 0 , k , val);
		if(mid + 1 <= k) update(rs , mid + 1 , r , k , val);
		sml[now] = min(sml[ls] , sml[rs]);
	}
}
PII query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return sml[now];
	else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return min(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}

int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) pre[i] = v[x[i]] , v[x[i]] = i;
	cin >> m;
	REP(i , 1 , m + 1) cin >> q[i][0] >> q[i][1];
	REP(i , 1 , m + 1) sol[q[i][1]].pb(i);
	REP(i , 1 , n + 1){
		if(pre[i] != 0) update(1 , 1 , n , pre[i] , mp(INF , INF));
		update(1 , 1 , n , i , mp(pre[i] , i));
		// DB4("update = " , i , pre[i] , i);
		for(auto to : sol[i]){
			PII tmp = query(1 , 1 , n , q[to][0] , q[to][1]);
			// DBGG(tmp.A , tmp.B);
			if(tmp.A >= q[to][0]) ans[to] = 0;
			else ans[to] = x[tmp.B];
		}
	}
	REP(i , 1 , m + 1) cout << ans[i] << endl;
    return 0;
}