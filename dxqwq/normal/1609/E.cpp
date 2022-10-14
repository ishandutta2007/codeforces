// Problem: E. William The Oblivious 
// Contest: Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node
{
	int f[3][3][2];
	//(/,a,ab),(/,b,bc),(/,c)
}a[524288];
char s[100003];
node merge(const node&A,const node&B)
{
	node res;
	memset(res.f,0x3f,sizeof(res.f));
	for(int i0=0; i0<3; ++i0)
		for(int j0=0; j0<3; ++j0)
			for(int k0=0; k0<2; ++k0)
	for(int i1=0; i1<3; ++i1)
		for(int j1=0; j1<3; ++j1) if(!(i0&&j1==2))
			for(int k1=0; k1<2; ++k1) if(!(i0==2&&k1==1))
				// printf("%d %d %d %d %d %d\n",i0,j0,k0,i1,j1,k1),
			 res.f[max(i0?j1?2:i0:0,i1)][max(j0?k1?2:j0:0,j1)][k0|k1]=
			 min(res.f[max(i0?j1?2:i0:0,i1)][max(j0?k1?2:j0:0,j1)][k0|k1],
			 A.f[i0][j0][k0]+B.f[i1][j1][k1]);	
	return res;
}
void build(int l,int r,int id)
{
	if(l==r)
	{
		memset(a[id].f,0x3f,sizeof(a[id].f));
		a[id].f[0][0][0]=1;
		if(s[l]=='a') a[id].f[1][0][0]=0;
		else if(s[l]=='b') a[id].f[0][1][0]=0;
		else a[id].f[0][0][1]=0;
		return ;
	}	
	int mid=(l+r)>>1;
	build(l,mid,id<<1),build(mid+1,r,(id<<1)+1);
	a[id]=merge(a[id<<1],a[(id<<1)+1]);
	return ;
}
void update(int l,int r,int x,int id,char v)
{
	if(l==r)
	{
		memset(a[id].f,0x3f,sizeof(a[id].f));
		a[id].f[0][0][0]=1;
		if(v=='a') a[id].f[1][0][0]=0;
		else if(v=='b') a[id].f[0][1][0]=0;
		else a[id].f[0][0][1]=0;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid) update(l,mid,x,id<<1,v);
	else update(mid+1,r,x,(id<<1)+1,v);
	a[id]=merge(a[id<<1],a[(id<<1)+1]);
	return ;
}
signed main()
{
	int n=read(),m=read();
	scanf("%s",s+1);
	build(1,n,1);
	// int ans=0x3f3f3f3f;
		// for(int i0=0; i0<3; ++i0)
			// for(int j0=0; j0<3; ++j0)
				// for(int k0=0; k0<2; ++k0)
					// ans=min(ans,a[1].f[i0][j0][k0]);
		// printf("%d\n",ans);
	for(int i=1; i<=m; ++i)
	{
		int x=read();
		char y=getchar();
		while(!islower(y)) y=getchar();
		int ans=0x3f3f3f3f;
		update(1,n,x,1,y);
		for(int i0=0; i0<3; ++i0)
			for(int j0=0; j0<3; ++j0)
				for(int k0=0; k0<2; ++k0)
					ans=min(ans,a[1].f[i0][j0][k0]);
		printf("%d\n",ans);
	}
	return 0;
}