/*input
6 7
5 1 4 2 3 6
2 5 3 1 4 6
1 1 2 4 5
2 2 4
1 1 2 4 5
1 2 3 3 5
1 1 6 1 2
2 4 1
1 4 4 1 3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++ i)
#define RREP(i, j, k) for(int i = j; i >= k; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int, int>
#define ALL(i) i.begin(), i.end()
#define DBGG(i, j) cout << i << " " << j << endl
#define DB4(i, j, k, l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0), cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200900
#define INF 0x3f3f3f3f

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> TREE;

TREE bit[MAX];
void update(int v1 , int v2 , int val){
	for(int i = v1 ; i < MAX ; i += i & -i){
		if(val == 1) bit[i].insert(v2);
		if(val == -1) bit[i].erase(v2);
	}
}
int query(int v1 , int v2){
	if(v1 == 0 || v2 == 0) return 0;
	int cnt = 0;
	for(int i = v1 ; i > 0 ; i -= i & -i){
		cnt += bit[i].order_of_key(v2 + 1);
	}
	return cnt;
}
int n , m , a[MAX] , b[MAX] , x[MAX] , c[MAX] , d[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) cin >> b[i];
	REP(i , 1 , n + 1) c[b[i]] = i;
	REP(i , 1 , n + 1) d[a[i]] = i;

	REP(i , 1 , n + 1) x[i] = c[a[i]];
	// REP(i , 1 , n + 1) cout << x[i] << " " ; cout << endl;
	REP(i , 1 , n + 1) update(i , x[i] , 1);
	REP(i , 1 , m + 1){
		int type , l , r , v1 , v2;
		cin >> type;
		if(type == 1){
			cin >> l >> r >> v1 >> v2;
			int cnt = 0;
			cnt += query(r , v2);
			cnt -= query(l - 1 , v2);
			cnt -= query(r , v1 - 1);
			cnt += query(l - 1 , v1 - 1);
			cout << cnt << endl;
		}
		else {
			cin >> l >> r;
			v1 = b[l] , v2 = b[r] , swap(b[l] , b[r]);
			v1 = d[v1] , v2 = d[v2];
			update(v1 , x[v1] , -1);
			update(v2 , x[v2] , -1);
			swap(x[v1] , x[v2]);
			update(v1 , x[v1] , 1);
			update(v2 , x[v2] , 1);
		}
	}
    return 0;
}