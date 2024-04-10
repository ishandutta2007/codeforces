#include<bits/stdc++.h>
using namespace std;
const int N=7000,M=N+70,L=1e5+50;
int n,q,mindiv[M],p[M],tot,mu[M];
bitset<M>b[M],m[M],g[L];
int read(){
	int x=0,c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))x=x*10+(c^48),c=getchar();
	return x;
}
int main(){
	n=read();q=read();mu[1]=1;
	for(int i=1;i<=N;i++)for(int j=i;j<=N;j+=i)b[j].set(i);
	for(int i=2;i<=N;i++){
		if(!mindiv[i])mindiv[i]=p[++tot]=i,mu[i]=1;
		for(int j=1,y;j<=tot&&p[j]<=mindiv[i]&&(y=p[j]*i)<=N;j++)
			mindiv[y]=p[j],mu[y]=i%p[j]?mu[i]:0;
	}
	for(int i=1;i<=N;i++)for(int j=1;j*i<=N;j++)if(mu[j])m[i].set(i*j);
	for(int i=1,op,x,y;i<=q;i++){
		op=read();x=read();y=read();
		if(op==1)g[x]=b[y];
		if(op==2)g[x]=g[y]^g[read()];
		if(op==3)g[x]=g[y]&g[read()];
		if(op==4)putchar('0'+((g[x]&m[y]).count()&1));
	}
	return 0;
}