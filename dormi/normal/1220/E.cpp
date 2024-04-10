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
const int MAXN=2e5+1;
lli val[MAXN];
vector<int> matrix[MAXN];
int cur=1;
int pind=1;
int ind[MAXN];
int low[MAXN];
int partof[MAXN];
int size[MAXN];
vector<int> matrixt[MAXN];
lli value[MAXN];
stack<int> st;
bool inst[MAXN];
void tarjan(int loc, int parent){
	ind[loc]=cur;
	low[loc]=cur++;
	st.push(loc);
	inst[loc]=true;
	for(int x:matrix[loc]){
		if(x!=parent){
			if(!ind[x]){
				tarjan(x,loc);
				low[loc]=min(low[loc],low[x]);
			}
			else if(inst[x])low[loc]=min(low[loc],ind[x]);
		}
	}
	if(low[loc]==ind[loc]){
		while(1){
			int te=st.top();
			st.pop();
			size[pind]++;
			partof[te]=pind;
			inst[te]=false;
			if(te==loc)break;
		}
		pind++;
	}
}
pll dfs(int loc, int parent){
	pll best={0,0};
	bool work=(size[loc]>1);
	lli bestdown=0;
	for(int x:matrixt[loc]){
		if(x!=parent){
			pll te=dfs(x,loc);
			if(te.second!=-1){
				work=true;
				best.second+=te.second;
				bestdown=max(bestdown,te.first-te.second);
				if(te.second!=-1)best.first+=te.second;
			}
			else bestdown=max(bestdown,te.first);
		}
	}
	best.first+=bestdown+value[loc];
	if(work)best.second+=value[loc];
	else best.second=-1;
	return best;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,s;
    sc(n,m);
    int a,b;
    rep(i,1,n+1)sc(val[i]);
    rep(i,0,m){
		sc(a,b);
		matrix[a].push_back(b);
	    matrix[b].push_back(a);
    }
    sc(s);
	tarjan(s,-1);
	rep(i,1,n+1){
		value[partof[i]]+=val[i];
		for(int x:matrix[i]){
			if(partof[x]!=partof[i]){
				matrixt[partof[i]].push_back(partof[x]);
			}
		}
	}
	pll te=dfs(partof[s],0);
	prl(max(te.first,te.second));
    return 0;
}