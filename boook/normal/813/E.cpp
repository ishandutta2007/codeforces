/*input
6 2
1 1 1 2 2 2
5
1 6
4 3
1 1
2 6
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
#define endl "\n"
///------------------------------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)

int sum[MAX * 40] , ls[MAX * 40] , rs[MAX * 40] , root[MAX] , po = 2;
int n , m , k , x[MAX];
queue<int> v[MAX];
int update(int dot , int l , int r , int k , int val){
	int now = po ++;
	sum[now] = sum[dot];
	ls[now] = ls[dot];
	rs[now] = rs[dot];
	if(l == k && r == k) sum[now] += val;
	else {
		if(k <= mid + 0) ls[now] = update(ls[now] , l , mid + 0 , k , val);
		if(mid + 1 <= k) rs[now] = update(rs[now] , mid + 1 , r , k , val);
		sum[now] = sum[ls[now]] + sum[rs[now]];
	}
	return now;
}
int query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return sum[now];
	if(qr <= mid + 0) return query(ls[now] , l , mid + 0 , ql , qr);
	if(mid + 1 <= ql) return query(rs[now] , mid + 1 , r , ql , qr);
	return query(ls[now] , l , mid + 0 , ql , qr) + query(rs[now] , mid + 1 , r , ql , qr);
}
int32_t main(){
	IOS , cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i];

	root[0] = 1;
	REP(i , 1 , n + 1){
		root[i] = root[i - 1];
		v[x[i]].push(i);
		if(v[x[i]].size() > k){
			int fr = v[x[i]].front();
			v[x[i]].pop();
			root[i] = update(root[i] , 1 , n , fr , -1);
		}
		root[i] = update(root[i] , 1 , n , i , 1);
	}
	cin >> m;
	int las = 0;
	REP(i , 1 , m + 1){
		int l , r;
		cin >> l >> r;
		l = (l + las) % n + 1;
		r = (r + las) % n + 1;
		if(l > r) swap(l , r);
		// DB4("l = " , l , "r = ",  r);
		las = query(root[r] , 1 , n , l , r);
		cout << las << endl;
	}
    return 0;
}