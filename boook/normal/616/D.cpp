/*input
9 3
6 5 1 2 3 2 1 4 5
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
#define int long long
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int n , k , x[MAX] , v[MAX] , p[MAX];
int sum[MAX * 4];
void update(int now , int l , int r , int k , int val){
	if(l == k && r == k) sum[now] += val;
	else {
		if(k <= mid + 0) update(ls , l , mid + 0 , k , val);
		if(mid + 1 <= k) update(rs , mid + 1 , r , k , val);
		sum[now] = sum[ls] + sum[rs];
	}
}
int query(int now , int l , int r , int k){
	if(l == r) return l;
	else {
		if(sum[rs] >= k) return query(rs , mid + 1 , r , k);
		else return query(ls , l , mid + 0 , k - sum[rs]);
	}
}
int32_t main(){
	IOS , cin >> n >> k;
	update(1 , 0 , n , 0 , INF);
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1){
		p[i] = v[x[i]];
		v[x[i]] = i;
	}
	int l = 1 , r = 1;
	REP(i , 1 , n + 1){
		update(1 , 0 , n , p[i] , -1);
		update(1 , 0 , n , i , 1);
		int tmp = query(1 , 0 , n , k + 1); tmp ++;
		if(r - l < i - tmp) l = tmp , r = i;
	}
	cout << l << " " << r << endl;
    return 0;
}