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
pii dis[MAXN];
int find(int a){
	if(dis[a].first==a)return a;
	return dis[a].first=find(dis[a].first);
}
void uni(int a, int b){
	int ap=find(a),bp=find(b);
	if(dis[ap].second<dis[bp].second)swap(ap,bp);
	dis[bp].first=ap;
	dis[ap].second+=dis[bp].second;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,m;
	sc(n,m);
	int longest[n+1];
	rep(i,1,n+1){
		dis[i]={i,1};
		longest[i]=i;
	}
	int a,b;
	rep(i,0,m){
		sc(a,b);
        if(b<a)swap(a,b);
        if(find(a)!=find(b))uni(a,b);
        longest[a]=max(longest[a],b);
	}
	int extend=1;
	int from=1;
	int am=0;
	rep(i,1,n+1){
		extend=max(extend,longest[i]);
		if(extend==i){
			set<int> pars;
			for(int j=from;j<=extend;j++){
				pars.insert(find(j));
			}
			am+=sz(pars)-1;
			from=i+1;
			extend=i+1;
		}
	}
	prl(am);
    return 0;
}