#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e10;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=1005;


int n,m,l,s,t;

struct edgpnt:pii{
	int id;
	edgpnt(int a,int b,int c){
		fr=a,sc=b,id=c;
	}
};

vector<edgpnt> v[N];
int vis[1005];

int dijkstra(int w,int idx = -1){
	mem0(vis);
	set<pii> d;
	d.insert({0,s});
	while(!d.empty()){
		pii k=*d.begin();
		int x=k.sc;
		int dis=k.fr;
		if(x==t){
			return dis;
		}
		d.erase(d.begin());
		if(vis[x])continue;
		vis[x]=1;
		for(edgpnt y:v[x]){
			int cw = y.sc;
			if(!cw){
				cw=w;
				if(y.id <= idx){
					cw--;
				}
			}
			d.insert({dis+cw,y.fr});
		}
	}
	return INF;
}

struct edge{
	int x,y,w,id;
}edg[10*N];



void solve(){
	cin>>n>>m>>l>>s>>t;
	swap(s,t);
	rep(i,0,m){
		int x,y,w;
		cin>>x>>y>>w;
		edg[i]={x,y,w,i};
		v[x].pb({y,w,i});
		v[y].pb({x,w,i});
	}
	
	// cout<<dijkstra(1)<<" "<<dijkstra(INF)<<"\n\n\n\n\n";
	
	if(dijkstra(INF) < l || dijkstra(1) > l){
		cout<<"NO";
		return;
	}
	
	int L=1,U=INF,ans=INF,idx=-1;
	while(L<=U){
		int m=(L+U)/2;
		int d=dijkstra(m);
		if(d < l){
			L=m+1;
		}
		else{
			ans=m;
			U=m-1;
		}
	}
	cout<<"YES\n";
	
	if(dijkstra(ans) != l){
		L=0,U=m-1;
		while(L<=U){
			int m=(L+U)/2;
			if(dijkstra(ans,m) > l){
				L=m+1;
			}
			else{
				idx=m;
				U=m-1;
			}
		}
	}
	
	rep(i,0,m){
		if(edg[i].w==0){
			edg[i].w=ans;
			if(i <= idx)edg[i].w--;
		}
		cout<<edg[i].x<<" "<<edg[i].y<<" "<<edg[i].w<<"\n";
	}
	
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}