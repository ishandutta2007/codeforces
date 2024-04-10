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
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=3e5+1;
vector<int> matrix[MAXN];
int dp[MAXN][2];
int ans=0;
void dfs(int loc, int parent){
	vector<int> bests;
	vector<int> bests2;
	for(int x:matrix[loc]){
		if(x!=parent){
			dfs(x,loc);
			bests.push_back(dp[x][0]);
			bests2.push_back(dp[x][1]);
		}
	}
	bests.push_back(0);
	bests.push_back(0);
	bests2.push_back(0);
	bests2.push_back(0);
	sort(bests.begin(),bests.end(),greater<int>());
	sort(bests2.begin(),bests2.end(),greater<int>());
	ans=max(ans,1+max(bests2[0]+bests2[1]+sz(bests2)-(bests2[0]?1:0)-(bests2[1]?1:0)-2,bests[0]));
	dp[loc][0]=1+bests2[0]+bests2[1]+sz(bests2)-(bests2[0]?1:0)-(bests2[1]?1:0)-2;
	dp[loc][1]=1+bests2[0]+sz(bests2)-(bests2[0]?1:0)-2;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    sc(q);
    while(q--){
    	int n;
    	sc(n);
    	ans=0;
    	rep(i,1,n+1){
    		matrix[i].clear();
    	}
    	int a,b;
    	rep(i,1,n){
    		sc(a,b);
    		matrix[a].push_back(b);
    		matrix[b].push_back(a);
    	}
		dfs(1,0);
    	prl(ans);
    }
    return 0;
}