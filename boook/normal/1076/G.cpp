/*input
5 1 3
1 1 3 3 4
2 1 5
2 2 5
2 3 5
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long 
#define MAX 200900
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)
const int INF = 0x3f3f3f3f;

struct N{
	int x[6] , r[6];
} st[MAX * 4];
int n , m , k , x[MAX] , tag[MAX * 4];
N pull(N a , N b){
	N ans;
	REP(i , 0 , m + 1){
		ans.x[i] = a.x[b.x[i]];
		ans.r[i] = a.r[b.r[i]];
	}
	return ans;
}
void build(int now , int l , int r){
	if(l == r){
		REP(i , 0 , m + 1){

			if(i == 0) st[now].x[i] = (x[l] ^ 0) == 1 ? 0 : 1;
			else if(i <  m) st[now].x[i] = i + 1;
			else if(i == m) st[now].x[i] = 0;

			if(i == 0) st[now].r[i] = (x[l] ^ 1) == 1 ? 0 : 1;
			else if(i <  m) st[now].r[i] = i + 1;
			else if(i == m) st[now].r[i] = 0;
		}
	}
	else {
		build(ls , l , mid + 0);
		build(rs , mid + 1 , r);
		st[now] = pull(st[ls] , st[rs]);
	}
	// cout << "status = " << l << " " << r << " " << now << ":: = ";
	// REP(i , 0 , m + 1) cout << st[now].x[i] << " "; cout << endl;
}
void push(int now , int l , int r){
	if(tag[now] && l != r){
		tag[ls] ^= 1;
		tag[rs] ^= 1;
		REP(i , 0 , m + 1) swap(st[ls].x[i] , st[ls].r[i]);
		REP(i , 0 , m + 1) swap(st[rs].x[i] , st[rs].r[i]);
		tag[now] = 0;
	}
}
void modify(int now , int l , int r , int ql , int qr){
	push(now , l , r);
	if(ql <= l && r <= qr){
		tag[now] ^= 1;
		REP(i , 0 , m + 1) swap(st[now].x[i] , st[now].r[i]);
	}
	else{
		if(ql <= mid + 0) modify(ls , l , mid + 0 , ql , qr);
		if(mid + 1 <= qr) modify(rs , mid + 1 , r , ql , qr);
		st[now] = pull(st[ls] , st[rs]);
	}
}
N query(int now , int l , int r , int ql , int qr){
	push(now , l , r);
	if(ql <= l && r <= qr) return st[now];
	else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return pull(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> x[i] , x[i] = (x[i] + 1) % 2;
	build(1 , 1 , n);
	// N tmp = pull(st[6] , st[7]);
	// REP(i , 0 , m + 1) cout << tmp.x[i] << " "; cout << endl;

	REP(i , 1 , k + 1){
		int type , l , r , d;
		cin >> type;
		if(type == 1){
			cin >> l >> r >> d;
			if(d % 2 == 1) modify(1 , 1 , n , l , r);
		}
		if(type == 2){
			cin >> l >> r;
			N res = query(1 , 1 , n , l , r);
			// cout << "---" << endl;
			// REP(i , 0 , m + 1) cout << res.x[i] << " "; cout << endl;
			cout << (res.x[0] == 1 ? 2 : 1) << endl;
		}
	}
    return 0;
}