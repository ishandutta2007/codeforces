#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 1000000
#define N 1048576
int a[MN+5],t[N*2+5];
inline void add(int k){for(k+=N;k;k>>=1)++t[k];}
int query(int l,int r)
{
	int res=0;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)res+=t[l+1];
		if( r&1)res+=t[r-1];
	}
	return res;
}
int main()
{
	int n=read(),i;long long s=0;
	for(i=1;i<=n;++i)s+=query(a[i]=read(),n),add(a[i]);
	puts((s-n)&1?"Um_nik":"Petr");
}