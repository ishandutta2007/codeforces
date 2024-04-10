/*input
5
1 2 2 3 3
3
2 5 3
2 5 2
1 5 5
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
#define MAX 100900
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)

struct N{ int ml , mr , big , ok; } b[MAX * 20];
int n , m , x[MAX] , root[MAX] , ls[MAX * 20] , rs[MAX * 20] , po = 2;

vector<int> uni , v[MAX];
N Pull(N a , N b){
	N ans = {a.ml , b.mr , max(a.big , b.big) , a.ok && b.ok};
	ans.big = max(ans.big , a.mr + b.ml);
	if(a.ok) ans.ml = a.ml + b.ml;
	if(b.ok) ans.mr = a.mr + b.mr;
	return ans;
}
int update(int dot , int l , int r , int k){
	int now = po ++;
	b[now] = b[dot] , ls[now] = ls[dot] , rs[now] = rs[dot];
	if(l == r) b[now] = N{1 , 1 , 1 , 1};
	else {
		if(k <= mid + 0) ls[now] = update(ls[now] , l , mid + 0 , k);
		if(mid + 1 <= k) rs[now] = update(rs[now] , mid + 1 , r , k);
		b[now] = Pull(b[ls[now]] , b[rs[now]]);
	}
	return now;
}
N query(int now , int l , int r , int ql , int qr){
	if(ql <= l && r <= qr) return b[now];
	if(qr <= mid + 0) return query(ls[now] , l , mid + 0 , ql , qr);
	if(mid + 1 <= ql) return query(rs[now] , mid + 1 , r , ql , qr);
	return Pull(query(ls[now] , l , mid + 0 , ql , qr) , query(rs[now] , mid + 1 , r , ql , qr));
}
void solveinit(){
	REP(i , 1 , n + 1) uni.pb(x[i]);
	sort(ALL(uni)) , uni.resize(unique(ALL(uni)) - uni.begin());
	REP(i , 1 , n + 1) x[i] = lower_bound(ALL(uni) , x[i]) - uni.begin() + 1;
	REP(i , 1 , n + 1) v[x[i]].pb(i);

	RREP(i , uni.size() , 1){
		root[i] = root[i + 1];
		for(auto to : v[i]){
			root[i] = update(root[i] , 1 , n , to);
		}
	}
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	solveinit();
	cin >> m;
	REP(i , 1 , m + 1){
		int ql , qr , k , ans = 1;
		cin >> ql >> qr >> k;
		RREP(j , 20 , 0){
			int to = ans + (1 << j);
			if(to <= uni.size() && query(root[to] , 1 , n , ql , qr).big >= k) ans = to;
		}
		cout << uni[ans - 1] << endl;
	}
    return 0;
}