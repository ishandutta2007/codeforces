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
#define int int_fast64_t
#define MAX 100900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)

int big[MAX * 4] , sum[MAX * 4];
int n , m , x[MAX];
void build(int now , int l , int r){
	if(l == r) big[now] = sum[now] = x[l];
	else {
		build(ls , l , mid + 0);
		build(rs , mid + 1 , r);
		big[now] = max(big[ls] , big[rs]);
		sum[now] = sum[ls] + sum[rs];
	}
}
int query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return sum[now];
	if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return query(ls , l , mid + 0 , ql , qr) + query(rs , mid + 1 , r , ql , qr);
}
void modify(int now , int l , int r , int ql , int qr , int val){
	if(big[now] < val) return ;
	if(ql <= l && r <= qr){
		if(l == r) big[now] = sum[now] = sum[now] % val;
		else {
			modify(ls , l , mid + 0 , ql , qr , val);
			modify(rs , mid + 1 , r , ql , qr , val);
			big[now] = max(big[ls] , big[rs]);
			sum[now] = sum[ls] + sum[rs];
		}
	}
	else {
		if(ql <= mid + 0) modify(ls , l , mid + 0 , ql , qr , val);
		if(mid + 1 <= qr) modify(rs , mid + 1 , r , ql , qr , val);
		big[now] = max(big[ls] , big[rs]);
		sum[now] = sum[ls] + sum[rs];
	}
}
void update(int now , int l , int r , int k , int val){
	if(l == r) big[now] = sum[now] = val;
	else {
		if(k <= mid + 0) update(ls , l , mid + 0 , k , val);
		if(mid + 1 <= k) update(rs , mid + 1 , r , k , val);
		big[now] = max(big[ls] , big[rs]);
		sum[now] = sum[ls] + sum[rs];
	}
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    build(1 , 1 , n);
    REP(i , 1 , m + 1){
    	int ty , l , r , k;
    	cin >> ty;
    	if(ty == 1){
    		cin >> l >> r;
    		cout << query(1 , 1 , n , l , r) << endl;
    	}
    	if(ty == 2){
    		cin >> l >> r >> k;
    		modify(1 , 1 , n , l , r , k);
    	}
    	if(ty == 3){
    		cin >> l >> k;
    		update(1 , 1 , n , l , k);
    	}
    }
    return 0;
}