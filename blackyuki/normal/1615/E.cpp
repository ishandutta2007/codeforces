#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define siz(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

constexpr int mod = 1e7;
//constexpr int inf = 3e18;

int N,M;
int par[200005],point[200005];
vector<int>ans[200005];
signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	cin>>N>>M;
    vector<vector<int>> G(N);
	rep(i,N-1){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
	}
    vector<int> srt;
    function<void(int,int)> dfs=[&](int i,int p){
        srt.push_back(i);
        par[i]=p;
        for(int x:G[i])if(x!=p)dfs(x,i);
    };dfs(0,-1);
    reverse(srt.begin(),srt.end());
	vector<int>V;
	for(int i:srt){
		if(ans[i].empty()){
			ans[par[i]].pb(1);
			continue;
		}
		sort(all(ans[i]),greater<>());
		if(i)ans[par[i]].pb(ans[i][0]+1);
		else V.pb(ans[0][0]+1);
		REP(j,ans[i].size())V.pb(ans[i][j]);
	}
	sort(all(V),greater<>());
    while(V.back()==0)V.pop_back();
    if(M>V.size()){
        int t=min(M,N/2);
        chmax(t,(int)(V.size()));
        cout<<t*(N-t)<<endl;
    }
	else{
        // for(int x:V)cout<<x<<endl;
        int res=0;
	    rep(i,M)res+=V[i];
        res=N-res;
        chmin(res,N/2);
	    cout<<(N-res-M)*(M-res)<<"\n";
    }
}