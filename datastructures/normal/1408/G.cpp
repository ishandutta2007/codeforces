#include <iostream>
#include <cstdio>
#include <algorithm>
#include <random>
#include <ctime>
#include <vector>
#include <cstring>
#define mod 998244353
#define ull unsigned long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n;
ull qwq[3005],awa[3005];
mt19937 rnd(time(NULL));
int tot,id[3005];
vector<int> e[3005];
struct node{
	int id,val;
	bool operator <(const node &x)const{
		return val<x.val;
	}
}c[3005][3005];
struct val_node{
	int id;
	ull val;
	bool operator <(const val_node &x)const{
		return val<x.val;
	}
}d[3005];
int ovo[3005];
void check(int len){
	if (len==1){
		++tot;
		e[id[ovo[1]]].push_back(tot);
		for (int i=1;i<=len;i++)id[ovo[i]]=tot;
		return;
	}
	int mn=1000000000,mx=0;
	for (int i=1;i<=len;i++)
		mx=max(mx,c[ovo[i]][len].val),mn=min(mn,c[ovo[i]][len+1].val);
	if (mx<mn){
		++tot;
		e[id[ovo[1]]].push_back(tot);
		for (int i=1;i<=len;i++)id[ovo[i]]=tot;
	}
	return;
}
int sz[3005],f[3005][3005],g[3005];
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
void dfs(int now){
	f[now][0]=1;
	sz[now]=1;
	for (int i=0;i<e[now].size();i++){
		dfs(e[now][i]);
		memset(g,0,sizeof(g));
		for (int j=0;j<=sz[now];j++)
			for (int k=0;k<=sz[e[now][i]];k++)
				upd(g[j+k],1ll*f[now][j]*f[e[now][i]][k]%mod);
		for (int j=0;j<=2000;j++)f[now][j]=g[j];
		sz[now]+=sz[e[now][i]];
	}
	f[now][0]=0;
	f[now][1]=1;
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)qwq[i]=1ull*rnd()*rnd()+rnd();
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			c[i][j].id=j,c[i][j].val=read();
		sort(c[i]+1,c[i]+1+n);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			awa[i]^=qwq[c[i][j].id];
	tot=1;
	for (int i=1;i<=n;i++)id[i]=tot;
	for (int i=n-1;i>=1;i--){
		for (int j=1;j<=n;j++)
			awa[j]^=qwq[c[j][i+1].id];
		for (int j=1;j<=n;j++)d[j].id=j,d[j].val=awa[j];
		sort(d+1,d+1+n);
		for (int j=1;j<=n;){
			int k=j;
			while(k<=n&&d[k].val==d[j].val)k++;
			if (k-j==i){
				for (int l=1;l<=k-j;l++)ovo[l]=d[j+l-1].id;
				check(i);
			}
			j=k;
		}
	}
	dfs(1);
	for (int i=1;i<=n;i++)printf("%d ",f[1][i]);
	puts("");
	return 0;
}