#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int isp[10005],tot,p[10005],mu[10005];
int n,q,opt,x,y,z;
bitset<7005> f[100005],c[7005],d[7005];
void prework(int maxn){
	isp[0]=isp[1]=1;
	mu[1]=1;
	for (int i=2;i<=maxn;i++){
		if (isp[i]==0){
			p[++tot]=i;
			mu[i]=-1;
		}
		for (int j=1;j<=tot&&p[j]*i<=maxn;j++){
			isp[i*p[j]]=1;
			if (i%p[j]==0){
				mu[i*p[j]]=0;
				break;
			}
			mu[i*p[j]]=-mu[i];
		}
	}
	for (int i=1;i<=maxn;i++)
		for (int j=1;j<=i;j++)
			if (i%j==0)c[i][j]=1;
	for (int i=1;i<=maxn;i++)
		for (int j=1;j<=maxn/i;j++)
			if (mu[j]!=0)d[i][i*j]=1;
	return;
}
int main(){
	prework(7000);
	cin>>n>>q;
	while(q--){
		opt=read();
		if (opt==1){
			x=read(),y=read();
			f[x]=c[y];
		}
		if (opt==2){
			x=read(),y=read(),z=read();
			f[x]=f[y]^f[z];
		}
		if (opt==3){
			x=read(),y=read(),z=read();
			f[x]=f[y]&f[z];
		}
		if (opt==4){
			x=read(),y=read();
			putchar('0'+((f[x]&d[y]).count()&1));
		}
	}
	puts("");
	return 0;
}