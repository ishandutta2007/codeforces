#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    sc(t);
    while(t--){
    	int n,m;
    	sc(n,m);
	    map<int,vector<pii>,greater<int>> nums;
	    int a;
	    vector<int> col[m];
	    rep(i,0,n)rep(j,0,m){
	    	sc(a);
	    	nums[a].push_back({i,j});
	    	col[j].push_back(a);
	    }
	    int needed=min(n,m);
	    set<int> cols;
	    for(auto x:nums){
		    bool done=false;
		    for(auto y:x.second){
			    cols.insert(y.second);
			    if(cols.size()==needed){
				    done=true;
				    break;
			    }
		    }
		    if(done)break;
	    }
	    vector<int> usecol;
	    usecol.push_back(-1);
	    for(int x:cols){
		    usecol.push_back(x);
	    }
		int dp[needed+1][(1<<n)];
	    int precalc[needed+1][(1<<n)];
	    rep(i,1,needed+1){
	    	rep(j,0,(1<<n)){
	    		precalc[i][j]=0;
	    	    rep(k,0,n){
	    	    	int sum=0;
	    	    	rep(l,0,n){
	    	    		if(j&(1<<l))sum+=col[usecol[i]][l];
	    	    	}
					precalc[i][j]=max(precalc[i][j],sum);
	    	    	rotate(col[usecol[i]].begin(),col[usecol[i]].end()-1,col[usecol[i]].end());
	    	    }
	    	}
	    }
	    rep(i,0,(1<<n))dp[0][i]=0;
	    rep(i,1,needed+1){
	    	rep(j,0,(1<<n)){
	    		dp[i][j]=dp[i-1][j];
	    		for(int k=j;k;k=(k-1)&j){
	    			dp[i][j]=max(dp[i][j],dp[i-1][j-k]+precalc[i][k]);
	    		}
	    	}
	    }
	    int ans=0;
	    rep(i,0,(1<<n)){
	    	ans=max(ans,dp[needed][i]);
	    }
	    prl(ans);
    }
    return 0;
}