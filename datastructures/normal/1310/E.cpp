#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
using namespace std;
int n,k,f[2025][2025],g[2025][2025];
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
int dfs1(int sum,int num){
	if (sum>n)return 0;
	if (f[sum][num]!=-1)return f[sum][num];
	int ans=1;
	upd(ans,dfs1(sum+1,num+1));
	upd(ans,dfs1(sum+num,num));
	f[sum][num]=ans;
	return ans;
}
int dfs2(int sum,int num){
	if (sum>n)return 0;
	if (g[sum][num]!=-1)return g[sum][num];
	int ans=1;
	upd(ans,dfs2(sum+(num+1),num+1));
	upd(ans,dfs2(sum+num*(num+1)/2,num));
	g[sum][num]=ans;
	return ans;
}
int ans,c[10005];
int d[10005],tot;
int _d[10005],_tot;
void trans(){
	_tot=tot;
	for (int i=1;i<=_tot;i++)_d[i]=d[i];
	tot=0;
	for (int i=_tot;i>=1;i--)
		for (int j=1;j<=_d[i];j++)
			d[++tot]=_tot-i+1;
	return;
}
bool check(int len){
	tot=len;
	for (int i=1;i<=tot;i++)d[i]=c[i];
	for (int i=1;i<k;i++){
		trans();
		int sum=0;
		for (int j=1;j<=tot;j++)sum+=d[j];
		if (sum>n)return 0;
	}
	return 1;
}
void dfs3(int now,int sum){
	if (sum>=65||sum>n)return;
	if (!check(now))return;
	if (now>0)ans++;
	for (int i=c[now];sum+i<=65&&sum+i<=n;i++){
		c[now+1]=i;
		dfs3(now+1,sum+i);
	}
	return;
}
int main(){
	cin>>n>>k;
	memset(f,-1,sizeof(f));
	memset(g,-1,sizeof(g));
	if (k==1)cout<<dfs1(1,1)<<endl;
	if (k==2)cout<<dfs2(1,1)<<endl;
	if (k>2){
		c[0]=1;
		dfs3(0,0);
		cout<<ans<<endl;
	}
	return 0;
}