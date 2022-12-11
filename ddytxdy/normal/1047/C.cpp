#include<bits/stdc++.h>
using namespace std;
const int N=1e6,M=1.5e7+10;
int n,mindiv[M],a[N],p[N],tot,g,num[M],dat;
int read(){
	int x=0,c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))x=x*10+(c^48),c=getchar();
	return x;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),g=g?gcd(g,a[i]):a[i];
	for(int i=1;i<=n;i++)a[i]/=g;
	for(int i=2;i<M;i++){
		if(!mindiv[i])mindiv[i]=p[++tot]=i;
		for(int j=1,y;j<=tot&&p[j]<=mindiv[i]&&(y=p[j]*i)<M;j++)
			mindiv[y]=p[j];
	}
	for(int i=1;i<=n;i++)
		while(a[i]!=1){
			int pp=mindiv[a[i]];num[pp]++;
			while(a[i]%pp==0)a[i]/=pp;
		}
	for(int i=1;i<=tot;i++)dat=max(dat,num[p[i]]);
	printf("%d\n",dat?n-dat:-1);
	return 0;
}