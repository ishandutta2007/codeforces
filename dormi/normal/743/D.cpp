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
const int MAXN=2e5+1;
lli val[MAXN];
vector<int> matrix[MAXN];
lli best=LLONG_MIN;
pair<lli,lli> dfs(int loc, int parent){
	vector<lli> vals;
	lli sum=val[loc];
	for(int x:matrix[loc]){
		if(x!=parent){
			pair<lli,lli> te=dfs(x,loc);
			vals.push_back(te.first);
			sum+=te.second;
		}
	}
	sort(vals.begin(),vals.end(),greater<lli>());
	if(sz(vals)>1)best=max(best,vals[0]+vals[1]);
	return {max(sum,sz(vals)?vals[0]:LLONG_MIN),sum};
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    rep(i,1,n+1)sc(val[i]);
    int a,b;
    rep(i,1,n){
    	sc(a,b);
    	matrix[a].push_back(b);
    	matrix[b].push_back(a);
    }
    dfs(1,0);
    prl(best==LLONG_MIN?"Impossible":to_string(best));
    return 0;
}