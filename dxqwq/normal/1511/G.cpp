// Problem: G. Chips on a Board
// Contest: Codeforces - Educational Codeforces Round 107 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1511/problem/G
// Memory Limit: 512 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
// zhoukangyang 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<20],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s*=10,s+=ch^48,ch=getchar();
	return s;
}
int cnt=1;
int A[5000003][6];
inline int add(int cur,int i)
{
	int t=++cnt;
	A[t][0]=A[cur][3],A[t][1]=A[cur][0],
	A[t][2]=A[cur][1],A[t][3]=A[cur][2],
	A[t][5]=A[cur][5],A[t][4]=A[cur][4]^A[A[cur][3]][4],
	A[t][4]-=(A[t][4]&((i<<2)-1));
	if(A[t][0]) A[t][0]=add(A[t][0],i<<2);
	A[t][4]^=A[A[t][0]][4],
	((A[A[t][1]][5]+A[A[t][3]][5])&1)&&(A[t][4]+=i),
	((A[A[t][2]][5]+A[A[t][3]][5])&1)&&(A[t][4]+=i<<1);
	return t;
}
int ans[200003];
struct query
{
	int l,r,bl,id;
	bool operator<(const query&t)const{return bl<t.bl||(bl==t.bl&&r<t.r);}
}q[200003];
bool f[200003];
signed main()
{
	int T=read(),n=read();
	for(int i=1; i<=T; ++i) f[read()]^=1;
	//for(int i=1; i<=n; ++i) f[i]=1;
	int m=read();
	int B=sqrt(1ll*n*n/m)/2+5;
	for(int i=1; i<=m; ++i) q[i].l=read(),q[i].r=read(),q[i].bl=q[i].l/B,q[i].id=i; 
	//for(int i=1; i<=m; ++i) q[i].l=i%n+1,q[i].r=n,q[i].bl=q[i].l/B,q[i].id=i; 
	sort(q+1,q+m+1);
	//return 0;
	for(int i=1,l=B,r=B-1; i<=m; ++i)
	{
		if(q[i].bl!=q[i-1].bl)
			cnt=1,memset(A[1],0,24),
			l=(q[i].bl+1)*B,r=l-1;
		if(q[i].r<l) for(int j=q[i].l; j<=q[i].r; ++j) (f[j])&&(ans[q[i].id]^=j-q[i].l);  
		else
		{
			while(r<q[i].r) 
			{
				++r;
				if(f[r])
				for(int i=0,cur=1,c,x=r-l; i<=18; i+=2,cur=A[cur][c])
					c=(x>>i)&3,
					(!A[cur][c])&&(A[cur][c]=++cnt,memset(A[cnt],0,24)),
					A[cur][4]^=x-(x&((1<<i)-1)),
					++A[cur][5];
			}
			int C=cnt,R=1;
			for(int j=q[i].l; j<l; ++j) (f[j])&&(ans[q[i].id]^=j-q[i].l);
			for(int j=q[i].l; j<l; ++j) R=add(R,1);
			ans[q[i].id]^=A[R][4],cnt=C;
		}
	}
	for(int i=1; i<=m; ++i) *O++="AB"[(ans[i]==0)];
	fwrite(obuf,O-obuf,1,stdout);
    return 0;
}
//