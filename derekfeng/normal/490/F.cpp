#include <bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
vector<int>g[6004];
int n,n_=1,dat[20004],colored,inv[6004];
int a[6004],numv[6004],cntv=0,dp[6004];
map<int,int>mp;
int ans=0;
void update(int id,int x){
	dat[id]=x;
	int idd=id;
	if (idd!=0) while(1){
		idd=(idd-1)/2;
		dat[idd]=max(dat[idd*2+1],dat[idd*2+2]);
		if (idd==0) break;
	}
}
int recovery(int l,int r,int a,int b,int id){
	if (r<a || b<l) return 0;
	if (a<=l && r<=b) return dat[id];
	int get_=recovery(l,(l+r)/2,a,b,id*2+1);
	if (get_==dat[id]) return get_;
	return max(get_,recovery((l+r)/2+1,r,a,b,id*2+2)); 
}
void dfs(int x,int par){
	int get_,lastv=dat[inv[x]+n_-1];
	if (inv[x]!=0) get_=recovery(0,n_-1,0,inv[x]-1,0)+1;
	else get_=1;
	ans=max(ans,get_);
	update(inv[x]+n_-1,get_);
	for (int i=0;i<g[x].size();++i) if (g[x][i]!=par)
		dfs(g[x][i],x);
	update(inv[x]+n_-1,lastv);
}
int main(){
	read(n);
	for (int i=1;i<=n;i++){
		read(a[i]);
		numv[cntv++]=a[i];
	}
	for (int i=0;i<n-1;i++){
		int x,y;read(x),read(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	sort (numv,numv+cntv);
	for (int i=0;i<n;i++)
		if (i==0 || numv[i]!=numv[i-1]) mp[numv[i]]=colored++;
	for (int i=1;i<=n;++i) inv[i]=mp[a[i]];
	while (n_<colored)n_<<=1;
	for (int i=1;i<=n;++i)
		if (g[i].size()==1)dfs(i,-1);
	write(ans);
}