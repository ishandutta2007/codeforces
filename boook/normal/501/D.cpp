/*input
3
1 2 0
2 1 0
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
#define MAX 200900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int bit[MAX];
void update(int from , int val){
	for(int i = from + 10 ; i < MAX ; i += i & -i)
		bit[i] += val;
}
int query(int from){
	int cnt = 0;
	for(int i = from + 10 ; i > 0 ; i -= i & -i)
		cnt += bit[i];
	return cnt;
}
int siz[MAX * 4] , qu;
void Build(int now , int l , int r){
	if(l == r) siz[now] = 1;
	else {
		Build(ls , l , mid + 0);
		Build(rs , mid + 1 , r);
		siz[now] = siz[ls] + siz[rs];
	}
}
void Find(int now , int l , int r , int k){
	if(l == r) siz[now] = 0 , qu = l;
	else {
		if(siz[ls] >= k) Find(ls , l , mid + 0 , k);
		else 			 Find(rs , mid + 1 , r , k - siz[ls]);
		siz[now] = siz[ls] + siz[rs];
	}
}
int n , a[MAX] , b[MAX] , ans[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) cin >> b[i];

	RREP(i , n , 1) update(a[i] , 1) , a[i] = query(a[i] - 1);
	MEM(bit , 0);
	RREP(i , n , 1) update(b[i] , 1) , b[i] = query(b[i] - 1);
	MEM(bit , 0);
	REP(i , 1 , n + 1) ans[i] = a[i] + b[i];

	// REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;

	RREP(i , n , 1){
		ans[i - 1] += ans[i] / (n + 1 - i);
		ans[i - 0]  = ans[i] % (n + 1 - i);
	}
	// REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
	Build(1 , 0 , n - 1);
	REP(i , 1 , n + 1){
		Find(1 , 0 , n - 1 , ans[i] + 1) , ans[i] = qu;
	}
	REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
    return 0;
}