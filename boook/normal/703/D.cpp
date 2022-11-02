/*input
7
1 2 1 3 3 2 3
5
4 7
4 5
1 3
1 7
1 5
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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int n , m , x[MAX] , pre[MAX] , l[MAX] , r[MAX] , sol[MAX] , ans[MAX];
int cmp(int a , int b){
	return r[a] < r[b];
}
int b[MAX * 4];
void update(int now , int l , int r , int k , int val){
	if(l == k && r == k) b[now] = val;
	else {
		if(k <= mid + 0) update(ls , l , mid + 0 , k , val);
		if(mid + 1 <= k) update(rs , mid + 1 , r , k , val);
		b[now] = b[ls] ^ b[rs];
	}
}
int query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return b[now];
	else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return query(ls , l , mid + 0 , ql , qr) ^ query(rs , mid + 1 , r , ql , qr);
}
map<int , int> cc;
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) pre[i] = pre[i - 1] ^ x[i];
	cin >> m;
	REP(i , 1 , m + 1) cin >> l[i] >> r[i];
	REP(i , 1 , m + 1) sol[i] = i;
	REP(i , 1 , m + 1) ans[i] = pre[r[i]] ^ pre[l[i] - 1];

	sort(sol + 1 , sol + 1 + m , cmp);
	int po = 0;
	REP(i , 1 , m + 1){
		int id = sol[i];
		while(po < r[id]){
			int val = x[++ po];
			update(1 , 0 , n , cc[val] , 0);
			cc[val] = po;
			update(1 , 0 , n , po , val);
		}
		ans[id] = query(1 , 0 , n , l[id] , r[id]) ^ ans[id];
	}
	REP(i , 1 , m + 1) cout << ans[i] << endl;
    return 0;
}