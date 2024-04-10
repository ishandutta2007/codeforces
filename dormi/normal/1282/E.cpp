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
const int MAXN=1e5+1;
pair<int,pii> tri[MAXN];
set<int> locs[MAXN];
bool gone[MAXN];
bool verg[MAXN];
map<int,int> share[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    sc(t);
    while(t--){
    	int n;
    	sc(n);
    	int a,b,c;
    	rep(i,1,n+1)share[i].clear(),verg[i]=false;
    	rep(i,1,n-1){
		    gone[i]=false;
    		sc(a,b,c);
    		tri[i]={a,{b,c}};
    		share[a][b]+=1;
		    share[a][c]+=1;
		    share[b][a]+=1;
		    share[b][c]+=1;
		    share[c][a]+=1;
		    share[c][b]+=1;
    		locs[a].insert(i);
		    locs[b].insert(i);
		    locs[c].insert(i);
    	}
    	vector<int> p;
    	queue<int> ver;
    	ver.push(1);
    	verg[1]=true;
    	while(sz(ver)){
    		int cur=ver.front();
    		ver.pop();
    		p.push_back(cur);
    		for(auto x:share[cur]){
    			if(x.second==1&&!verg[x.first]){
    				ver.push(x.first);
    				verg[x.first]=true;
    				break;
    			}
    		}
    	}
    	queue<int> togo;
    	rep(i,1,n+1){
    		if(sz(locs[i])==1&&!gone[*locs[i].begin()]){
    			togo.push(*locs[i].begin());
    			gone[*locs[i].begin()]=true;
    		}
    	}
    	vector<int> q;
    	while(sz(togo)){
    		int cur=togo.front();
    		togo.pop();
    		q.push_back(cur);
    		locs[tri[cur].first].erase(cur);
    		if(sz(locs[tri[cur].first])==1&&!gone[*locs[tri[cur].first].begin()]){
    				gone[*locs[tri[cur].first].begin()]=true;
    				togo.push(*locs[tri[cur].first].begin());
    		}
		    locs[tri[cur].second.first].erase(cur);
		    if(sz(locs[tri[cur].second.first])==1&&!gone[*locs[tri[cur].second.first].begin()]){
			    gone[*locs[tri[cur].second.first].begin()]=true;
			    togo.push(*locs[tri[cur].second.first].begin());
		    }
		    locs[tri[cur].second.second].erase(cur);
		    if(sz(locs[tri[cur].second.second])==1&&!gone[*locs[tri[cur].second.second].begin()]){
			    gone[*locs[tri[cur].second.second].begin()]=true;
			    togo.push(*locs[tri[cur].second.second].begin());
		    }
	    }
    	for(int x:p)pr(x,"");
    	prl("");
	    for(int x:q)pr(x,"");
	    prl("");
    }
    return 0;
}