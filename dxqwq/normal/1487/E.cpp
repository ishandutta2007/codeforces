#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[200003],b[200003],c[200003],d[200003],st[200003][19],l2[200003];
int N;
inline void init(int l,int*A)
{
	st[l][0]=A[l];
	for(int i=1; i<=18; i++) st[l][i]=min(st[l][i-1],st[min(l+(1<<(i-1)),N)][i-1]);
}
inline int query(int l,int r)
{
	int L=l2[r-l+1];
	return min(st[l][L],st[min(r-(1<<L)+1,N)][L]);
}
vector<int> v[200003];
int f[200003];

signed main()
{
	int n1=read(),n2=read(),n3=read(),n4=read();
	for(int i=1; i<=n1; i++) a[i]=read();
	for(int i=1; i<=n2; i++) b[i]=read();
	for(int i=1; i<=n3; i++) c[i]=read();
	for(int i=1; i<=n4; i++) d[i]=read();
    for(int i=2; i<=200000; i++) l2[i]=l2[i>>1]+1;
    int m;
    memset(st,0,sizeof(st));N=n1;
	for(int i=n1; i; --i) init(i,a);
	m=read();
	for(int i=1,x,y; i<=m; i++) x=read(),y=read(),v[y].push_back(x);
	memset(f,0x3f,sizeof(f));
	for(int i=1; i<=n2; ++i)
	{
		sort(v[i].begin(),v[i].end());
		int lst=1;
		for(int x:v[i])
		{
			if(lst<x) f[i]=min(f[i],query(lst,x-1));
			lst=x+1;
		}
		if(lst<=n1) f[i]=min(f[i],query(lst,n1));
		v[i].clear(),f[i]+=b[i];
	}
	//-----------------
	//-----------------
    memset(st,0,sizeof(st));N=n2;
	for(int i=n2; i; --i) init(i,f);
	m=read();
	for(int i=1,x,y; i<=m; i++) x=read(),y=read(),v[y].push_back(x);
	memset(f,0x3f,sizeof(f));
	for(int i=1; i<=n3; ++i)
	{
		sort(v[i].begin(),v[i].end());
		int lst=1;
		for(int x:v[i])
		{
			if(lst<x) f[i]=min(f[i],query(lst,x-1));
			lst=x+1;
		}
		if(lst<=n2) f[i]=min(f[i],query(lst,n2));
		v[i].clear(),f[i]+=c[i];
	}
	//-----------------
	//-----------------
	memset(st,0,sizeof(st));N=n3;
	for(int i=n3; i; --i) init(i,f);
	m=read();
	for(int i=1,x,y; i<=m; i++) x=read(),y=read(),v[y].push_back(x);
	memset(f,0x3f,sizeof(f));
	for(int i=1; i<=n4; ++i)
	{
		sort(v[i].begin(),v[i].end());
		int lst=1;
		for(int x:v[i])
		{
			if(lst<x) f[i]=min(f[i],query(lst,x-1));
			lst=x+1;
		}
		if(lst<=n3) f[i]=min(f[i],query(lst,n3));
		v[i].clear(),f[i]+=d[i];
	}
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int i=1; i<=n4; i++) ans=min(ans,f[i]);
	if(ans==0x3f3f3f3f3f3f3f3f) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}