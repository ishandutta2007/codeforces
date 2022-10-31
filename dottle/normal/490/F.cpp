#define cxy ak ioi
#include<bits/stdc++.h>
#define vi vector<int>
const int N=100500;
using namespace std;

vector<int> u[N],d[N];
int ans;
int n,a[N];
int sn[N],dp[N];

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

void mrg(int x,int y){
	if(u[x].size()<u[y].size())swap(u[x],u[y]);
	for(int i=0;i<u[y].size();i++)
		u[x][i]=min(u[x][i],u[y][i]);
	if(d[x].size()<d[y].size())swap(d[x],d[y]);
	for(int i=0;i<d[y].size();i++)
		d[x][i]=max(d[x][i],d[y][i]);
}
void upa(int x){
	ans=max(ans,(int)u[x].size());
	ans=max(ans,(int)d[x].size());
}
void upans(int x,int y){
	for(int i=0;i<u[y].size();i++){
		auto t=lower_bound(d[x].begin(),d[x].end(),u[y][i],greater<int>());
		if(t!=d[x].begin())
			ans=max(ans,(int)(i+(t-d[x].begin())+1));
	}
	for(int i=0;i<d[y].size();i++){
		auto t=lower_bound(u[x].begin(),u[x].end(),d[y][i]);
		if(t!=u[x].begin())
			ans=max(ans,(int)(i+(t-u[x].begin())+1));
	}
}
void push(int x,int p){
	auto t=lower_bound(u[x].begin(),u[x].end(),p);
	if(t==u[x].end())u[x].push_back(p);else *t=p;
	 	 t=lower_bound(d[x].begin(),d[x].end(),p,greater<int>());
	if(t==d[x].end())d[x].push_back(p);else *t=p;
}

void dfs(int k,int fa){
	dp[k]=1;
	fore(k)if(_to!=fa){
		dfs(_to,k);
		dp[k]=max(dp[k],dp[_to]+1);
		sn[k]=dp[sn[k]]>dp[_to]?sn[k]:_to;
	}
}
void df5(int k,int fa){
	if(sn[k]){
		df5(sn[k],k);
		swap(u[k],u[sn[k]]);
		swap(d[k],d[sn[k]]);
	}
	push(k,a[k]);
	fore(k)if(_to!=fa&&_to!=sn[k]){
		df5(_to,k);
		upans(k,_to);
		push(_to,a[k]);
		mrg(k,_to);
	}
	upa(k);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	
		cin>>a[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs(1,0);
	df5(1,0);
	cout<<ans<<endl;
}