/*input
4 10
1 1
2 0
3 2
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , k , p[MAX] , w[MAX] , x[MAX];
vector<PII> v[MAX];
void DFS(int now){
	for(auto to : v[now]) x[to.F] = x[now] ^ to.S;
	for(auto to : v[now]) DFS(to.F);
}
struct N{
	int l , r , a , b;
};
inline PII getsiz(int l , int r , int bit){
	if((x[l] & (1ll << bit)) != 0) return mp(0 , r - l + 1);
	if((x[r] & (1ll << bit)) == 0) return mp(r - l + 1 , 0);
	int pos = l;
	while((x[pos] & (1ll << bit)) == 0) pos ++;
	return mp(pos - l , r - pos + 1);
}
int32_t main(){
	IOS;
	cin >> n >> k , k --;
	REP(i , 2 , n + 1) cin >> p[i] >> w[i];
	REP(i , 2 , n + 1) v[p[i]].pb(i , w[i]);
	DFS(1);
	sort(x + 1 , x + 1 + n);
	vector<N> sol;
	sol.pb(N{1 , n , 1 , n});

	// REP(i , 1 , n + 1) cout << x[i] << " "; cout << endl;
	// REP(i , 1 , n + 1) REP(j , 1 , n + 1) cout << (x[i] ^ x[j]) << " "; cout << endl;
	int ans = 0;
	RREP(bit , 62 , 0){
		vector<N> big , sml;
		int cnt = 0;
		// DB4("bit = " , bit , "size = " , sol.size());
		// cout << "---" << endl;
		for(auto to : sol){
			PII v1 = getsiz(to.l , to.r , bit);
			PII v2 = getsiz(to.a , to.b , bit);
			// if(to.l == to.a && to.r == to.b)
				 // cnt += v1.F * v2.F * 1 + v1.S * v2.S * 1;
			// else 
				cnt += v1.F * v2.F * 2 + v1.S * v2.S * 2;
// 0 0 1 3 
// 0 0 0 0 0 0 1 1 1 1 2 2 3 3 3 3 
			// cout << "siz = " << v1.F << v1.S << " " << v2.F << v2.S << endl;
			if(v1.F && v2.F) sml.pb(N{to.l , to.l + v1.F - 1 , to.a , to.a + v2.F - 1});
			if(v1.S && v2.S) sml.pb(N{to.r - v1.S + 1 , to.r , to.b - v2.S + 1 , to.b});

			if(v1.F && v2.S) big.pb(N{to.l , to.l + v1.F - 1 , to.b - v2.S + 1 , to.b});
			if(v1.S && v2.F) big.pb(N{to.r - v1.S + 1 , to.r , to.a , to.a + v2.F - 1});
		}
		cnt >>= 1;
		// for(auto to : sol) DB4(to.l , to.r , to.a , to.b);
		// cout << "---" << endl;
		// for(auto to : sml) DB4(to.l , to.r , to.a , to.b);
		// cout << "---" << endl;
		// for(auto to : big) DB4(to.l , to.r , to.a , to.b);
		// cout << "---" << endl;
		// DB4("cnt = " , cnt , "k = " , k);

		if(k >= cnt){
			// cout << "here" << bit << endl;
			k -= cnt , ans |= (1ll << bit); 
			swap(sol , big);
		}
		else{
			swap(sol , sml);
		}
	}
	cout << ans << endl;
    return 0;
}