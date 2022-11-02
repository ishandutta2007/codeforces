#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i++)
#define pb push_back
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
//--------------------------------------
#define MAX 100900

struct djs{
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){ x[Find(a)] = Find(b); }
	int operator[](int now){ return Find(now); }
} ds;
int dp[MAX] , good[MAX];
int n , m , all , w[MAX] , v[MAX] , gw[MAX] , gv[MAX];
vector<int> sol[MAX];
void DP(int ww , int vv){
	// DB4("ww = " , ww , "vv = " , vv);
	REP(i , ww , all + 1){
		good[i] = max(good[i] , dp[i - ww] + vv);
	}
}
int main(){
	IOS;
	cin >> n >> m >> all;
	REP(i , 1 , n + 1) cin >> w[i];
	REP(i , 1 , n + 1) cin >> v[i];
	ds.init();
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		ds.Union(a , b);
	}

	REP(i , 1 , n + 1){
		sol[ds[i]].pb(i);
		gw[ds[i]] += w[i];
		gv[ds[i]] += v[i];
	}
	REP(i , 1 , n + 1){
		if(sol[i].size()){
			REP(j , 0 , sol[i].size()){
				int id = sol[i][j];
				DP(w[id] , v[id]);
			}
			DP(gw[i] , gv[i]);
		}
		REP(j , 0 , all + 1) dp[j] = max(dp[j] , good[j]) , good[j] = 0;
	}
	cout << dp[all] << endl;
	return 0;
}