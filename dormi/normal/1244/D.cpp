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
const int MAXN=1e5+1;
lli val[MAXN][3];
vector<int> matrix[MAXN];
lli dp[MAXN][3][3];
int wh[MAXN];
int ord[3];
int ind=0;
void dfs(int loc, int par){
	for(int x:matrix[loc]){
		if(x!=par){
			dfs(x,loc);
			rep(i,0,3){
				rep(j,0,3){
					if(i!=j){
						set<int> te={0,1,2};
						te.erase(i),te.erase(j);
						dp[loc][i][j]=val[loc][i]+dp[x][j][*te.begin()];
					}
				}
			}
			return;
		}
	}
	rep(i,0,3){
		rep(j,0,3){
			if(i!=j){
				dp[loc][i][j]=val[loc][i];
			}
		}
	}
}
void dfss(int loc, int par){
	wh[loc]=ord[ind];
	ind=(ind+1)%3;
	for(int x:matrix[loc]){
		if(x!=par){
			dfss(x,loc);
		}
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	rep(j,0,3)rep(i,1,n+1)sc(val[i][j]);
	int a,b;
	rep(i,1,n){
		sc(a,b);
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	int begin=0;
	rep(i,1,n+1){
		if(sz(matrix[i])>2){
			prl("-1");return 0;
		}
		if(sz(matrix[i])==1)begin=i;
	}
	dfs(begin,0);
	lli mi=LLONG_MAX;
	rep(i,0,3){
		rep(j,0,3){
			if(i!=j){
				set<int> te={0,1,2};
				te.erase(i),te.erase(j);
				if(dp[begin][i][j]<mi){
					mi=dp[begin][i][j];
					ord[0]=i+1,ord[1]=j+1,ord[2]=(*te.begin())+1;
				}
			}
		}
	}
	prl(mi);
	dfss(begin,0);
	rep(i,1,n+1)pr(wh[i],"");
    return 0;
}