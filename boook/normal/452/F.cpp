/*input
5
1 5 2 4 3
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
#define PIII pair<PII , int>
#define int int_fast64_t
#define MAX 300900
#define mod 1000000007LL
#define AC 10430579LL
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)


PIII h[MAX * 4];
PIII pull(PIII x , PIII y){
	int fr = (x.A.A * y.B + y.A.A) % mod;
	int ba = (y.A.B * x.B + x.A.B) % mod;
	return mp(mp(fr , ba) , x.B * y.B % mod);
}
int update(int now , int l , int r , int k){
	if(l == r) h[now] = mp(mp(1 , 1) , AC);
	else{
		if(k <= mid + 0) update(ls , l , mid + 0 , k);
		if(mid + 1 <= k) update(rs , mid + 1 , r , k);
		h[now] = pull(h[ls] , h[rs]);
	}
}
PIII query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return h[now];
	if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return pull(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
void build(int now , int l , int r){
	if(l == r) h[now] = mp(mp(0 , 0) , AC);
	else {
		build(ls , l , mid + 0);
		build(rs , mid + 1 , r);
		h[now] = pull(h[ls] , h[rs]);
	}
}
int n , x[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	build(1 , 1 , n);
	REP(i , 1 , n + 1){
		update(1 , 1 , n , x[i]);
		int len = min(n - x[i] , x[i] - 1);
		if(len){
			PII fr = query(1 , 1 , n , x[i] - len , x[i] - 1).A;
			PII ba = query(1 , 1 , n , x[i] + 1 , x[i] + len).A;
			if(fr.A == ba.B && fr.B == ba.A);
			else return cout << "YES" << endl , 0;
		}
	}
	cout << "NO" << endl;
    return 0;
}