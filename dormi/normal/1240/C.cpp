#include<bits/stdc++.h>
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
const int MAXN=5e5+1;
vector<pair<int,lli>> matrix[MAXN];
lli dp[MAXN][2];
int n,k;
void dfs(int loc, int parent){
	priority_queue<lli,vector<lli>,greater<lli>> q;
	lli tot=0;
	int used=0;
	for(auto x:matrix[loc]){
		if(x.first!=parent){
			dfs(x.first,loc);
			if(dp[x.first][0]>=dp[x.first][1]+x.second){
				tot+=dp[x.first][0];
			}
			else{
				tot+=dp[x.first][1]+x.second;
				used+=1;
				q.push(dp[x.first][1]+x.second-dp[x.first][0]);
			}
		}
	}
	while(used>k){
		used-=1;
		tot-=q.top();
		q.pop();
	}
	dp[loc][0]=tot;
	while(used>=k){
		used-=1;
		tot-=q.top();
		q.pop();
	}
	dp[loc][1]=tot;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int q;
	sc(q);
	while(q--){
		sc(n,k);
		int a,b;
		lli w;
		rep(i,1,n+1)matrix[i].clear();
		rep(i,1,n){
			sc(a,b,w);
			matrix[a].push_back({b,w});
			matrix[b].push_back({a,w});
		}
		dfs(1,0);
		prl(dp[1][0]);
	}
	return 0;
}