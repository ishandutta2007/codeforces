/*input
5
1 2 3 4 5
6
1 1 4 2
2 3 6
1 1 4 2
1 1 5 2
2 5 10
1 1 5 2
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
#define MAX 500090
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int sum[MAX * 4] , n , m , x[MAX];
void Build(int now , int l , int r){
	if(l == r) sum[now] = x[l];
	else {
		Build(ls , l , mid + 0);
		Build(rs , mid + 1 , r);
		sum[now] = __gcd(sum[ls] , sum[rs]);
	}
}
void update(int now , int l , int r , int k , int val){
	if(l == r) sum[now] = val;
	else {
		if(k <= mid + 0) update(ls , l , mid + 0 , k , val);
		if(mid + 1 <= k) update(rs , mid + 1 , r , k , val);
		sum[now] = __gcd(sum[ls] , sum[rs]);
	}
}
int www = 0;
void query(int now , int l , int r , int ql , int qr , int val){
	if(www > 1 || sum[now] % val == 0) return;
	if(ql <= l && r <= qr){
		if(l == r) www ++;
		else {
			query(ls , l , mid + 0 , ql , qr , val);
			query(rs , mid + 1 , r , ql , qr , val);
		} 
	}
	else {
		if(ql <= mid + 0) query(ls , l , mid + 0 , ql , qr , val);
		if(mid + 1 <= qr) query(rs , mid + 1 , r , ql , qr , val);
	}
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	Build(1 , 1 , n);
	cin >> m;
	REP(i , 1 , m + 1){
		int ty , l , r , v;
		cin >> ty;
		if(ty == 1){
			cin >> l >> r >> v;
			www = 0;
			query(1 , 1 , n , l , r , v);
			if(www > 1) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
		else {
			cin >> l >> v;
			update(1 , 1 , n , l , v);
			x[l] = v;
		}
	}
    return 0;
}