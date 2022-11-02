#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(unsigned i = 0 ; i < j ; ++i)
#define REPNM(i,j,k)   for(unsigned i = j ; i < k ; ++i)
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
#define MAX 300090
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int n , m , N , x[MAX];
int gd[MAX * 4];
int q[MAX][3] , ans[MAX] , tr[MAX];
void Build(int now , int l , int r){
	if(l == r) gd[now] = x[l];
	else {
		Build(ls , l , mid);
		Build(rs , mid + 1 , r);
		gd[now] = __gcd(gd[ls] , gd[rs]);
	}
}
int query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return gd[now];
	else if(qr <= mid) return query(ls , l , mid , ql , qr);
	else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	else {
		int a = query(ls , l , mid , ql , qr);
		int b = query(rs , mid + 1 , r , ql , qr);
		return __gcd(a , b);
	}
}
int32_t main(){
	IOS;
	cin >> n;
	VPII sol;
	REPNM(i , 1 , n + 1) cin >> x[i] , sol.pb(mp(x[i] , i));
	Build(1 , 1 , n);
	sort(ALL(sol));
	cin >> m;
	REP(i , m){
		cin >> q[i][0] >> q[i][1];
		q[i][2] = query(1 , 1 , n , q[i][0] , q[i][1]);
		int from = lower_bound(ALL(sol) , mp(q[i][2] , q[i][0])) - sol.begin();
		int to = upper_bound(ALL(sol) , mp(q[i][2] , q[i][1])) - sol.begin();
		cout << (q[i][1] - q[i][0] + 1) - (to - from) << endl;
	}
    return 0;
}