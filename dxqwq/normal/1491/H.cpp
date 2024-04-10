// Problem: H. Yuezheng Ling and Dynamic Tree
// Contest: Codeforces - Codeforces Global Round 13
// URL: https://codeforces.com/problemset/problem/1491/H
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int B=500;
int a[110003];
int b[110003];
long long tag[210];
inline int rebuild(int x)
{
	int l=x*B,r=(x+1)*B;
	for(int i=l; i<r; ++i)
		b[i]=(a[i]-tag[x]>=l)?b[a[i]-tag[x]]:i;
	return 0;
}
bool f[210];
inline int Fill(int x)
{
	int l=x*B,r=(x+1)*B;
	for(int i=l; i<r; ++i)
		b[i]=i;
	f[x]=1;
	return 0;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<n; ++i) a[i]=read()-1; 
	for(int i=0; i<=n/B; ++i) rebuild(i);
	for(int op,x,y,z; m--;)
	{
		op=read(),x=read()-1,y=read()-1;
		if(op==1)
		{
			z=read();
			int l=x/B,r=y/B;
			if(l==r)
			{
				for(int i=x; i<=y; ++i) ((a[i]-=z)<0)&&(a[i]=0);
				rebuild(l);
			}
			else
			{
				for(int i=x,d=(l+1)*B; i<d; ++i) ((a[i]-=z)<0)&&(a[i]=0);
				for(int i=r*B; i<=y; ++i) ((a[i]-=z)<0)&&(a[i]=0);
				rebuild(l),rebuild(r);
				for(int i=l+1; i<r; ++i) ((tag[i]+=z)<=B)?(rebuild(i)):((!f[i])&&Fill(i));
			}
		}
		else
		{
			while(x/B!=y/B)
				(x<y)?(y=max(a[b[y]]-tag[y/B],0ll)):(x=max(a[b[x]]-tag[x/B],0ll));
			while(x!=y)
				(x<y)?(y=max(a[y]-tag[y/B],0ll)):(x=max(a[x]-tag[x/B],0ll));
			printf("%d\n",x+1);
		}
	}
	return 0;
}