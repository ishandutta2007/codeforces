/*input
7
24 63 13 52 6 10 1
6
3 5
4 7
1 7
2 4
3 6
2 6
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
// #define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mod 1000000007LL
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int dv[MAX] , p[MAX] , po = 0 , ni[MAX];
void solveinit(){
	ni[0] = ni[1] = dv[0] = dv[1] = 1;
	REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
	REP(i , 2 , MAX){
		if(dv[i] == 0) dv[i] = i , p[po ++] = i;
		REP(j , 0 , po){
			if(i * p[j] >= MAX) break;
			dv[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
}
int ppow(int a , int k){
	if(k == 0) return 1;
	if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
	if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int mul[MAX * 4];
void update(int now , int l , int r , int k , int val){
	if(l == k && r == k) mul[now] = val;
	else {
		if(k <= mid + 0) update(ls , l , mid + 0 , k , val);
		if(mid + 1 <= k) update(rs , mid + 1 , r , k , val);
		mul[now] = mul[ls] * mul[rs] % mod;
	}
}
int query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return mul[now];
	if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return query(ls , l , mid + 0 , ql , qr) * query(rs , mid + 1 , r , ql , qr) % mod;
}
// void Print(int now , int l , int r){
// 	if(l == r) cout << mul[now] << " ";
// 	else Print(ls , l , mid + 0) , Print(rs , mid + 1 , r);
// }
int n , m , x[MAX] , q[MAX][2] , pre[MAX] , ans[MAX] , sol[MAX];
int help[MAX] , upd[MAX];
int cmp(int a , int b){ return q[a][1] < q[b][1]; }
int32_t main(){
	solveinit();
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	cin >> m;
	REP(i , 1 , m + 1) cin >> q[i][0] >> q[i][1];
	
	
	pre[0] = 1;
	REP(i , 1 , n + 1) pre[i] = pre[i - 1] * x[i] % mod;
	REP(i , 1 , m + 1){
		ans[i] = pre[q[i][1]] * ppow(pre[q[i][0] - 1] , mod - 2) % mod;
	}

	REP(i , 1 , m + 1) sol[i] = i;
	sort(sol + 1 , sol + 1 + m , cmp);

	int r = 0;
	REP(i , 1 , m + 1){
		int id = sol[i];
		while(r < q[id][1]){

			int v = x[++r];
			upd[r] = 1;
			while(v != 1){
				int tmp = dv[v];
				while(v % tmp == 0) v /= tmp;
				upd[r] = upd[r] * (tmp - 1) % mod * ni[tmp] % mod;
				if(help[tmp]){
					int to = help[tmp];
					upd[to] = upd[to] * tmp % mod * ni[tmp - 1] % mod;
					update(1 , 1 , n , to , upd[to]);
				}
				help[tmp] = r;
			}
			update(1 , 1 , n , r , upd[r]);
		};
		// REP(i , 1 , n + 1) cout << upd[i] << " "; cout << endl;
		// Print(1 , 1 , n) , cout << endl;;
		// DB4("query = " , q[id][0] , q[id][1] , query(1 , 1 , n , q[id][0] , q[id][1]));
		ans[id] = ans[id] * query(1 , 1 , n , q[id][0] , q[id][1]) % mod;
	}


	REP(i , 1 , m + 1) cout << ans[i] << endl;
    return 0;
}