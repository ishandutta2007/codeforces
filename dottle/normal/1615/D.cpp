#include<bits/stdc++.h>
const int N=400050;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx,w,id;
}e[N<<1];int hd[N],S;
void add(int fr,int to,int w,int id){
    e[++S]=(edge){to,hd[fr],w,id},hd[fr]=S;
}

int calc(int k){int ans=0;while(k)ans++,k-=k&-k;return ans;}

vector<pair<int,int>> s1,s2;
vector<int> def[N];
void ad(int x,int y)
{
	def[x].push_back(y),def[y].push_back(x); 
}
void dfs(int k,int fa){
	fore(k)if(_to!=fa){
		if(e[i].w!=-1){
			if(calc(e[i].w)&1)s2.emplace_back(k,_to);
			else s1.emplace_back(k,_to);
		}
		dfs(_to,k);
	}
}

int fa[N],cl[N],v[N],FL,ans[N];

int gf(int k){return k==fa[k]?k:fa[k]=gf(fa[k]);}
void mrg(int x,int y){
	int fx=gf(x),fy=gf(y);
	if(fx!=fy)fa[fx]=fy;
}

void df5(int k,int c){
	if(cl[k]!=-1){
		if(cl[k]!=c)FL=1; 
		return ;
	}
	cl[k]=c;
	for(auto x:def[k])df5(x,c^1);
}

void df4(int k,int fa){
	fore(k)if(_to!=fa){
		if(e[i].w>=0)ans[e[i].id]=e[i].w;
		else ans[e[i].id]=!(cl[k]==cl[_to]);
		df4(_to,k);
	}
}

void solve(){
	int n,m;cin>>n>>m;
	s1.clear(),s2.clear();
	for(int i=1;i<=n;i++){
		hd[i]=0,fa[i]=i,cl[i]=-1,FL=0;
		def[i].clear();swap(def[i],def[0]);
	}S=0;
	for(int i=1;i<n;i++){
		int x,y,w;cin>>x>>y>>w;
		add(x,y,w,i),add(y,x,w,i);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		if(z==1)s2.emplace_back(x,y); 
		else s1.emplace_back(x,y);
	}
	for(auto x:s1)mrg(x.first,x.second);
	for(auto x:s2){
		int fx=gf(x.first),fy=gf(x.second);
		if(fx==fy){
			cout<<"NO"<<'\n';
			return ;	
		}
		ad(fx,fy);
	}
	for(int i=1;i<=n;i++)
		if(gf(i)==i&&cl[i]==-1)
			df5(i,0);
	for(int i=1;i<=n;i++)
		cl[i]=cl[gf(i)];
	if(FL){
		cout<<"NO"<<'\n';return; 
	}
	df4(1,0);
	cout<<"YES"<<'\n';
	for(int i=1;i<=S;i+=2)
		cout<<e[i+1].to<<' '<<e[i].to<<' '<<ans[(i>>1)+1]<<'\n';
}

int main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}