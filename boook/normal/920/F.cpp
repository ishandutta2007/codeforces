/*input
7 6
6 4 1 10 3 2 4
2 1 7
2 4 5
1 3 5
2 4 4
1 5 7
2 1 7
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
#define MAX 300800
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)
#define N 1000900

int big[MAX * 4] , sml[MAX * 4] , sum[MAX * 4];
int n , m , x[MAX] , dv[N] , p[N] , po = 0 , sol[N];
void Build(int now , int l , int r){
	if(l == r) big[now] = sml[now] = sum[now] = x[l];
	else{
		Build(ls , l , mid + 0);
		Build(rs , mid + 1 , r);
		big[now] = max(big[ls] , big[rs]);
		sml[now] = min(sml[ls] , sml[rs]);
		sum[now] = sum[ls] + sum[rs];
	}
}
void update(int now , int l , int r , int ql , int qr){
	if(big[now] <= 2) return;
	if(ql <= l && r <= qr){
		if(l == r) big[now] = sml[now] = sum[now] = sol[sum[now]];
		else {
			update(ls , l , mid + 0 , ql , qr);
			update(rs , mid + 1 , r , ql , qr);
			big[now] = max(big[ls] , big[rs]);
			sml[now] = min(sml[ls] , sml[rs]);
			sum[now] = sum[ls] + sum[rs];
		}
	}
	else {
		if(ql <= mid + 0) update(ls , l , mid + 0 , ql , qr);
		if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr);
		big[now] = max(big[ls] , big[rs]);
		sml[now] = min(sml[ls] , sml[rs]);
		sum[now] = sum[ls] + sum[rs];
	}
}
int query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return sum[now];
	else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return query(ls , l , mid + 0 , ql , qr) + query(rs , mid + 1 , r , ql , qr);
}
void solveinit(){
	REP(i , 2 , N){
		if(dv[i] == 0) dv[i] = i , p[po ++] = i;
		REP(j , 0 , po){
			if(i * p[j] >= N) break;
			dv[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
	// REP(i , 0 , 100) cout << dv[i] << " " ; cout << endl;
	REP(i , 3 , N){
		int res = 1 , cnt = 0 , tmp = i , pre = -1;
		while(tmp != 1){
			if(dv[tmp] == pre) cnt ++ , tmp /= dv[tmp];
			else {
				res *= cnt + 1; cnt = 1;
				pre = dv[tmp] , tmp /= dv[tmp];
			}
		}
		sol[i] = res * (cnt + 1);
		// if(i < 100) DBGG(i , sol[i]);
	}
}
int32_t main(){
	IOS , solveinit();
	// return 0;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	Build(1 , 1 , n);
	REP(i , 1 , m + 1){
		int ty , l , r;
		cin >> ty >> l >> r;
		if(ty == 1) update(1 , 1 , n , l , r);
		else cout << query(1 , 1 , n , l , r) << endl;
	}
    return 0;
}