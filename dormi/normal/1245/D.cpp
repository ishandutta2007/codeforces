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
pll coords[2001];
pii disjoint[2001];
lli thingy[2001];
int find(int a){
	if(a==disjoint[a].first)return a;
	return disjoint[a].first=find(disjoint[a].first);
}
void uni(int a, int b){
	int ap=find(a),bp=find(b);
	if(disjoint[ap].second<disjoint[bp].second)swap(ap,bp);
	disjoint[bp].first=ap;
	disjoint[ap].second+=disjoint[bp].second;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    priority_queue<pair<lli,pii>,vector<pair<lli,pii>>,greater<pair<lli,pii>>> q;
    disjoint[0]={0,1};
    rep(i,1,n+1){
    	disjoint[i]={i,1};
    	sc(coords[i].first,coords[i].second);
    }
    lli in;
    rep(i,1,n+1){
    	sc(in);
    	q.push({in,{0,i}});
    }
    rep(i,1,n+1){
		sc(thingy[i]);
    }
    rep(i,1,n+1){
    	rep(j,1,i){
    		q.push({(thingy[i]+thingy[j])*(abs(coords[i].first-coords[j].first)+abs(coords[i].second-coords[j].second)),{i,j}});
    	}
    }
    lli cost=0;
    vector<int> stations;
    vector<pii> connect;
    while(sz(q)){
    	auto te=q.top();
    	q.pop();
		if(find(te.second.first)==find(te.second.second))continue;
		uni(te.second.first,te.second.second);
		cost+=te.first;
		if(te.second.first==0){
			stations.push_back(te.second.second);
		}
		else connect.push_back(te.second);
    }
    prl(cost);
    prl(sz(stations));
    for(int x:stations)pr(x,"");
    prl("");
    prl(sz(connect));
    for(pii x:connect)prl(x.first,x.second);
    return 0;
}