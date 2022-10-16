#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,m,a[200005],c[35],qwq;
int cnt[1048576];
int f[65536],g[20][65536],h[65536],ans[35];
int lowbit(int x){
	return x&(-x);
}
void ins(int x){
	for (int i=34;i>=0;i--){
		if (x&(1ll<<i)){
			if (c[i]==0){
				c[i]=x;
				qwq++;
				break;
			}
			x^=c[i];
		}
	}
	return;
}
void dfs1(int w,int s){
	if (w<16){
		g[cnt[s>>16]][s&65535]++;
		return;
	}
	dfs1(w-1,s);
	if (c[w]!=0)dfs1(w-1,s^c[w]);
	return;
}
void dfs2(int w,int s){
	if (w<0){
		f[s]++;
		return;
	}
	dfs2(w-1,s);
	if (c[w]!=0)dfs2(w-1,s^c[w]);
	return;
}
void FWT(int w,int *f,int opt){
	for (int i=0;i<16;i++)
		for (int j=0;j<(1<<w);j+=(1<<(i+1)))
			for (int k=0;k<(1<<i);k++){
				f[j+k]+=f[j+k+(1<<i)];
				f[j+k+(1<<i)]=f[j+k]-f[j+k+(1<<i)]*2;
				if (opt!=1)f[j+k]=f[j+k]*opt%mod,f[j+k+(1<<i)]=f[j+k+(1<<i)]*opt%mod;
			}
	return;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<(1<<20);i++)cnt[i]=cnt[i-lowbit(i)]+1;
	for (int i=1;i<=n;i++){
		a[i]=read();
		ins(a[i]);
	}
	dfs1(34,0);
	dfs2(15,0);
	FWT(16,f,1);
	for (int i=0;i<20;i++){
		FWT(16,g[i],1);
		for (int j=0;j<65536;j++)h[j]=f[j]*g[i][j]%mod;
		FWT(16,h,(mod+1)/2);
		for (int j=0;j<65536;j++)ans[i+cnt[j]]=(ans[i+cnt[j]]+h[j])%mod;
	}
	int awa=1;
	for (int i=1;i<=n-qwq;i++)awa=awa*2%mod;
	for (int i=0;i<=m;i++)cout<<ans[i]*awa%mod<<' ';
	cout<<endl;
	return 0;
}