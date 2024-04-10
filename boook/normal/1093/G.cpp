/*input
5 2
1 2
2 3
3 4
4 5
5 6
7
2 1 5
2 1 3
2 3 5
1 5 -1 -2
2 1 5
1 4 -1 -2
2 1 5
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
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)

int n , m , k , x[MAX][5];
struct N{
	int b[32] , s[32];
} st[MAX * 4];
N pull(N a , N b){
	N ans;
	REP(i , 0 , 32){
		ans.b[i] = max(a.b[i] , b.b[i]);
		ans.s[i] = min(a.s[i] , b.s[i]);
	}
	return ans;
}
void build(int now , int l , int r){
	if(l == r){
		REP(i , 0 , 32){
			st[now].b[i] = 0;
			REP(j , 0 , 5){
				if(i & (1 << j))
					 st[now].b[i] += x[l][j];
				else st[now].b[i] -= x[l][j];
			}
			st[now].s[i] = st[now].b[i];
		}
	}
	else {
		build(ls , l , mid + 0);
		build(rs , mid + 1 , r);
		st[now] = pull(st[ls] , st[rs]);
		// REP(i , 0 , 32) cout << st[now].b[i] << " "; cout << endl;
		// REP(i , 0 , 32) cout << st[now].b[i] - st[now].s[i] << " "; cout << endl;
	}
}
void update(int now , int l , int r , int k){
	if(l == r){
		REP(i , 0 , 32){
			st[now].b[i] = 0;
			REP(j , 0 , 5){
				if(i & (1 << j))
					 st[now].b[i] += x[l][j];
				else st[now].b[i] -= x[l][j];
			}
			st[now].s[i] = st[now].b[i];
		}
	}
	else{
		if(k <= mid + 0) update(ls , l , mid + 0 , k);
		if(mid + 1 <= k) update(rs , mid + 1 , r , k);
		st[now] = pull(st[ls] , st[rs]);
	}
} 
N query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return st[now];
	else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
	else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
	return pull(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}

int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) REP(j , 0 , m) cin >> x[i][j];
	build(1 , 1 , n);
	cin >> k;
	REP(i , 1 , k + 1){
		int type;
		cin >> type;
		if(type == 1){
			int idx;
			cin >> idx;
			REP(j , 0 , m) cin >> x[idx][j];
			update(1 , 1 , n , idx);
		}
		if(type == 2){
			int l , r , ans = 0;
			cin >> l >> r;
			auto tmp = query(1 , 1 , n , l , r);
			REP(j , 0 , 32){
				ans = max(ans , tmp.b[j] - tmp.s[j]);
			}
			cout << ans << endl;
		}
	}
    return 0;
}