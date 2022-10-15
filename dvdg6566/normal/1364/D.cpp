#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define f first
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
const int MAXN=200100;
vi V[MAXN];
int d[MAXN];
int N,E,K,a,b;
vpi EL;
int p[MAXN];
stack<int> process;

void dfs(int x,int pa){
	process.push(x);
	p[x]=pa;
	for(auto v:V[x]){
		if(v==pa)continue;
		if(d[v]!=-1){
			if(x<v)EL.pb(x,v);
			continue;
		}
		d[v]=d[x]+1;
		dfs(v,x);
	}
}

int done[MAXN];

int main(){
	memset(d,-1,sizeof(d));	
	cin>>N>>E>>K;
	for(int i=0;i<E;++i){
		cin>>a>>b;V[a].pb(b);V[b].pb(a);
	}
	d[1]=0;
	dfs(1,-1);
	for(auto i:EL){
		int dt=abs(d[i.f]-d[i.s]);
		if(dt<K){
			if(d[i.s] < d[i.f])swap(i.f,i.s);
			cout<<"2\n"<<dt+1<<'\n';
			
			while(i.s!=i.f){
				cout<<i.s<<' ';	
				i.s=p[i.s];
			}
			cout<<i.f<<'\n';
			return 0;
		}
	}
	cout<<"1\n";
	K=(K+1)/2;
	for(int i=0;i<N;++i)if(K){
		int a=process.top();process.pop();
		if(done[a])continue;
		--K;
		cout<<a<<' ';
		done[a]=1;
		done[p[a]]=1;
	}
	if(K)assert(0);
}