#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int power[N];
int size[N],Do[N],Up[N],deep[N],son[N];
vector<pair<int,int>>e[N];
int n,Mo;
template<class T>void exgcd(T a,T b,T &x,T &y){
	if(!b)x=1,y=0;
	else{exgcd(b,a%b,x,y);T t=x;x=y;y=t-a/b*y;}
}
template<class T>T inv(T a){
	T b=Mo;
	T x,y;exgcd(a,b,x,y);
	return (x%b+b)%b;
}
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
map<int,int>D,U;
inline void Add(int u){
	int x=Up[u];U[x]++;
	int y=Do[u]*inv(power[deep[u]])%Mo;D[y]++;
}
void deal(int u,int fath){
	size[u]=1;
	for(auto sjyakioi:e[u]){
		int v=sjyakioi.first,w=sjyakioi.second;
		if(v==fath)continue;
		Up[v]=(Up[u]+power[deep[u]]%Mo*w)%Mo;
		Do[v]=(10*Do[u]%Mo+w)%Mo;
		deep[v]=deep[u]+1;
		deal(v,u);
		size[u]+=size[v];
		if(size[son[u]]<size[v])son[u]=v;
	}
}
int ans;
void cal(int pos,int LCA){
	int Ub=Up[pos],pl=power[deep[LCA]],pe=power[deep[pos]];
	int Dl=Do[LCA],De=Do[pos],Ul=Up[LCA]; 
	int x=((Dl* pl %Mo - De *pl %Mo* pl %Mo *inv(pe) %Mo+Ul)%Mo+Mo)%Mo;x=(x+Mo)%Mo;
    int y =(Dl*inv(pl)%Mo+(Ul-Ub)*inv(pl)%Mo*inv(pl)%Mo)%Mo;y=(y+Mo)%Mo;
	ans+=U[x];ans+=D[y];
}
void change(int u,int father,int LCA,bool _){
	if(_) cal(u,LCA);
	else Add(u);
	for(auto sjyakioi:e[u]){
		int v=sjyakioi.first;
		int w=sjyakioi.second;
		if(v==father)continue;
		change(v,u,LCA,_);
	}
}
void dfs(int u,int fath,bool heavy){
	for(auto sjyakioi:e[u]){
		int v=sjyakioi.first;
		int w=sjyakioi.second;
		if(v!=fath&&v!=son[u])
			dfs(v,u,0);
	}
	if(son[u])dfs(son[u],u,1);
	for(auto sjyakioi:e[u]){
		int v=sjyakioi.first;
		int w=sjyakioi.second;
		if(v==fath||v==son[u])continue;
		change(v,u,u,1);
		change(v,u,u,0);
	}
	cal(u,u);
	Add(u);
	if(!heavy)
		U.clear(),D.clear();
}
signed main(){
	power[0]=1;
	n=read();Mo=read();
	for(int i=1;i<=n;i++)power[i]=power[i-1]*10%Mo;
	for(int i=1,a,b,w;i<n;i++)
		a=read()+1,b=read()+1,w=read(),
		e[a].push_back(make_pair(b,w)),
		e[b].push_back(make_pair(a,w));
	deal(1,0);
	dfs(1,0,1);
	printf("%lld",ans);
}//Orz ZLC