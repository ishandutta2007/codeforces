/*input
4 2
1 1 2 2
1 3 2
1 4 2
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
#define MAX 300900
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)

int sum[MAX * 30] , ls[MAX * 30] , rs[MAX * 30] , po = 2;
int n , m , x[MAX] , root[MAX];
int update(int dot , int l , int r , int val){
	int now = po ++;
	ls[now] = ls[dot];
	rs[now] = rs[dot];
	sum[now] = sum[dot];
	if(l == val && r == val) sum[now] += 1;
	else {
		if(val <= mid + 0) ls[now] = update(ls[now] , l , mid + 0 , val);
		if(mid + 1 <= val) rs[now] = update(rs[now] , mid + 1 , r , val);
		sum[now] = sum[ls[now]] + sum[rs[now]];
	}
	return now;
}
int query(int lrt , int rrt , int l , int r , int k , int val){
	// DB4(l , r , k , val);	
	if(l == r){
		if(sum[rrt] - sum[lrt] >= val) return l;
		return INF;
	}
	else {
		int cnt = sum[ls[rrt]] - sum[ls[lrt]];
		if(cnt >= k) return query(ls[lrt] , ls[rrt] , l , mid + 0 , k , val);
		if(cnt <  k) return query(rs[lrt] , rs[rrt] , mid + 1 , r , k - cnt , val);
	}
}
int32_t main(){

	IOS , cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];

	root[0] = 1;
	REP(i , 1 , n + 1) root[i] = update(root[i - 1] , 1 , n , x[i]);

	REP(i , 1 , m + 1){
		int l , r , k;
		cin >> l >> r >> k;
		int tmp = max(1 , (r - l + 1) / k) , now = tmp , ans = INF;
		while(now <= r - l + 1){
			ans = min(ans , query(root[l - 1] , root[r] , 1 , n , now , (r - l + 1) / k + 1));
			now += tmp;
		}
		cout << (ans == INF ? -1 : ans) << endl;
	}
    return 0;
}