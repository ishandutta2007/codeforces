// Problem: C. Game with Stones
// Contest: Codeforces - Codeforces Round #755 (Div. 1, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.com/contest/1588/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//  - /

/*
+
++
+++
++++
+++++
++++++
+++++++
++++++++
+++++++++
++++++++++
+++++++++++
++++++++++++
+++++++++++++
++++++++++++++
+++++++++++++++
++++++++++++++++
+++++++++++++++++
++++++++++++++++++
+ +++++++++++++++++
+  ++++++++++++++ ++
+   +++++++++++++  ++
+    ++++++++++++   ++
+     +++++++++++    ++
+      ++++++++++     ++
+       +++++++++      ++
+        ++++++++       ++
+         +++++++++++++++++
+          +++++++++++++++++
+           ++++++++++++++
+            +++++++++++
+             ++++++++
+              +++++
+               ++
+               +
+               +
+              ++
+             +++
+            ++++
+           +++++
+           +++++
+           +++++
+           +++++
+     +     +++++
+    +++    +++++
+   ++ ++   +++++
+  ++   ++  +++++
+ ++  +  ++ +++++
+++  +++  +++++++
++  ++ ++  ++++++
 
 
 ++++++++      +++++++++++     +++      +++        ++++++++        ++++++++
+++++++++     +++++++++++++    +++      +++       +++    +++      +++    +++
+++          +++   +++   +++   +++      +++      +++   ++++++    +++      +++
+++          +++   +++   +++   +++      +++      +++ +++  +++           +++
+++          +++   +++   +++   +++ ++   +++ ++   ++++++   +++         +++
+++++++++    +++   +++   +++   +++ ++   +++ ++    +++    +++        +++    ++
 ++++++++    +++   +++   +++   +++++    +++++      ++++++++       +++++++++++
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
#include <assert.h>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
#define rg(x) for(int i=1;i<=(x);i++){
#define rg_(i,x) for(int i=1;i<=(x);i++){
#define fe(u) for(int i=h[u];i;i=e[i].nxt){int v=e[i].v;
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[2*n+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}
#define mgs int fa[1<<22],sz[1<<22];\
inline int f(int x){return x==fa[x]?x:fa[x]=f(fa[x]);}\
inline int u(int x,int y)\
{\
    int fx=f(x),fy=f(y);\
    if(fx==fy)return 0;\
    if(sz[fx]>sz[fy])fx^=fy^=fx^=fy;\
    fa[fx]=fy,sz[fy]+=sz[fx];\
    return 1;\
}
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
inline int re1d()
{
    char c=getchar();
    while(c<48||c>49)c=getchar();
    return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int a[300005];
std::map<int,std::vector<int> >mp;
int pre[2][2][300005];
int minn[2][22][300005],maxn[2][22][300005];
int lg[300005];
// int b[100005]
#define printf(...) 0
#define puts(...) 0
int querymax(int id,int l,int r)
{
	int d=lg[r-l+1];
	return max(maxn[id][d][l],maxn[id][d][r-(1<<d)+1]);
}
int querymin(int id,int l,int r)
{
	int d=lg[r-l+1];
	return min(minn[id][d][l],minn[id][d][r-(1<<d)+1]);
}
int check(int l,int r)
{
	int base=a[l-1];
	int A1=querymin(0,l,r)>=base&&querymax(1,l,r)<=base;
	int A2=querymin(1,l,r)>=base&&querymax(0,l,r)<=base;
	printf("\n~! %d %d\n",querymin(1,l,r),querymax(0,l,r));
	// // printf("checking %d %d\n",l,r);
	// if(l&1)
	// {
		// int len=r-l+1;
		// int odd=len+1>>1;
		// int even=len>>1;
		// // int A1=(pre[1][1][r]-pre[1][1][l-1]==odd)&&(pre[0][0][r]-pre[0][0][l-1]==even);
		// // int A2=(pre[1][0][r]-pre[1][0][l-1]==odd)&&(pre[0][1][r]-pre[0][1][l-1]==even);
		// int A1=qu
		// // odl(pre[1][1][1]);
		// return A1||A2;
	// }
	// int len=r-l+1;
	// int odd=len>>1;
	// int even=len+1>>1;
	// int A1=(pre[1][1][r]-pre[1][1][l-1]==odd)&&(pre[0][0][r]-pre[0][0][l-1]==even);
	// int A2=(pre[1][0][r]-pre[1][0][l-1]==odd)&&(pre[0][1][r]-pre[0][1][l-1]==even);
	return A1||A2;
	
}
signed main()
{
	lg[0]=-1;
	rg(300001)lg[i]=lg[i>>1]+1;gr
	int T=read();rg(T)
	int n=read();
	rg(n)a[i]=read();gr
	rg(n)if(i&1);else a[i]=-a[i];gr
	rg(n)a[i]+=a[i-1];gr
	// rg(n)odb(a[i]);gr puts("");
	mp.clear();
	rg(n)mp[a[i]].push_back(i);gr
	int ans=0;
	rrg(n+1){
	// minn[0
	if(i&1)
	{
		//minn >= 0
		minn[1][0][i]=a[i];
		maxn[1][0][i]=a[i];
		minn[0][0][i]=0x3f3f3f3f;
		maxn[0][0][i]=-0x3f3f3f3f;
	}
	else
	{
		minn[0][0][i]=a[i];
		maxn[0][0][i]=a[i];
		minn[1][0][i]=0x3f3f3f3f;
		maxn[1][0][i]=-0x3f3f3f3f;
	}
	printf("%d %d %d %d\n",minn[0][0][i],maxn[0][0][i],minn[1][0][i],maxn[1][0][i]);
	// printf("%d %d %d %d\n",pre[0][0][i],pre[0][1][i],pre[1][0][i],pre[1][1][i]);
	gr
	rg(20)for(int j=0;j+(1<<i)-1<=n;j++)minn[0][i][j]=min(minn[0][i-1][j],minn[0][i-1][j+(1<<i-1)]);gr
	rg(20)for(int j=0;j+(1<<i)-1<=n;j++)minn[1][i][j]=min(minn[1][i-1][j],minn[1][i-1][j+(1<<i-1)]);gr
	rg(20)for(int j=0;j+(1<<i)-1<=n;j++)maxn[0][i][j]=max(maxn[0][i-1][j],maxn[0][i-1][j+(1<<i-1)]);gr
	rg(20)for(int j=0;j+(1<<i)-1<=n;j++)maxn[1][i][j]=max(maxn[1][i-1][j],maxn[1][i-1][j+(1<<i-1)]);gr
	int aans=0;
	mp[0].push_back(0);
	rg(n)odb(a[i]);gr puts("");
	for(auto x:mp)
	{
		#define u v
		std::vector<int>& u=x.second;
		sort(u.begin(),u.end());
		// ans+=u.size()*(u.size()-1)/2;
		int t=0;
		odb(-1);
		for(auto x:u)
		{
			odb(x);
			int A=x+1;
			t++;
			int l=t,r=v.size();r--,ans=t-1;
			while(l<=r)
			{
				int m=l+r>>1;
				if(check(A,v[m]))ans=m,l=m+1;//odp(A,v[m]);
				else r=m-1;
			}
			aans+=ans-t+1;
		}
		puts("");
	}
	#undef printf
	oldl(aans);
	gr
	return 0;
}