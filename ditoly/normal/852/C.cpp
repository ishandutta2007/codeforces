#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MN 100000 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,rk[MN+5],B[MN+5],A[MN+5],y,Ans[MN+5];
bool cmp(int x,int y){return A[x]>A[y];}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) B[i]=read();B[0]=B[n];B[n+1]=B[1];
	for(int i=1;i<=n;++i) rk[i]=i,A[i]=n-B[i]-B[i+1];
	sort(rk+1,rk+n+1,cmp);
	for(int i=1;i<=n;++i)  Ans[rk[i]]=i-1; 
	for(int i=1;i<=n;++i) printf("%d\n",Ans[i]);
	return 0;
}