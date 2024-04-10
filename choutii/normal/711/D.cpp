#include<map>
#include<stack>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<complex>
#include<iostream>
#include<assert.h>
#include<algorithm>
using namespace std;
#define inf 1001001001
#define infll 1001001001001001001LL
#define ll long long
#define dbg(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define gmax(a,b) (a)=max((a),(b))
#define gmin(a,b) (a)=min((a),(b))
#define Ri register int
#define gc getchar()
#define il inline
il int read(){
	bool f=true;Ri x=0;char ch;while(!isdigit(ch=gc))if(ch=='-')f=false;while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=gc;}return f?x:-x;
}
#define gi read()
#define FO(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
int n,p[200005],vis[200005],cir[200005],cnt=0,ans=0;
void dfs(int v,int c){
	vis[v]=c;
	if(!vis[p[v]]){
		dfs(p[v],c); 
	}else{
		if(vis[p[v]]==c)cir[++ans]=p[v];
	}
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
	if(!vis[i]){
		++cnt;
		dfs(i,cnt);
	}
	bool flag=true;
	ll mod=1000000007;
	ll res=1;
	memset(vis,0,sizeof(vis));
	
	for(int i=1;i<=ans;i++){
		int fx=p[cir[i]],len=1;
		vis[cir[i]]=true; 
		while(fx!=cir[i]){
			vis[fx]=true;fx=p[fx];++len;
		}
		ll res_=1;
		for(int i=1;i<=len;i++)res_=res_*2%mod;
		res_=res_-2+mod;res_%=mod; 
		res=(res*res_)%mod;
	}
	for(int i=1;i<=n;i++)if(!vis[i])res=(res*2)%mod;
	cout<<res; 
}