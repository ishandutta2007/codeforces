// Problem: F. Jumping Through the Array
// Contest: Codeforces - Codeforces Round #755 (Div. 1, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.com/problemset/problem/1588/F
// Memory Limit: 512 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
ll a[200003],pre[200003],ans[503];
bool flg[200003],chg[200003],qwq[200003],qwqwq[200003];
int p[200003],nxt[200003],f[200003],tp[200003],bel[200003];
vector<int> v[200003];
struct node{int pos,id,val;};
vector<node> t[200003];
const int B=500;
struct query{int op,x,y;}q[503];
int n=read(),m=0,cnt=0;
bitset<200003> vis[503];
vector<int> opt[503];
void solve()
{
	memset(nxt,0,sizeof(nxt)),memset(flg,0,sizeof(flg)),
	memset(chg,0,sizeof(chg)),memset(qwqwq,0,sizeof(qwqwq)),
	memset(ans,0,sizeof(ans)),nxt[n+1]=n+1;
	for(int i=1; i<=m; ++i) 
		if(q[i].op==1) 
			nxt[q[i].x]=q[i].x,nxt[q[i].y]=q[i].y;
	for(int i=n; i>=0; --i) (!nxt[i])&&(nxt[i]=nxt[i+1]);
	for(int i=1; i<=m; ++i) 
		if(q[i].op==3) chg[q[i].x]=chg[q[i].y]=1;
	for(int i=1; i<=n; ++i) if(!qwqwq[i]) 
	{
		int x=i,sdt=0;
		while(!qwq[x]) (chg[x])&&(sdt=x),qwq[x]=qwqwq[x]=1,x=p[x];
		if(!sdt)
		{
			++cnt,tp[cnt]=cnt;
			while(qwq[x]) v[cnt].push_back(x),bel[x]=cnt,qwq[x]=0,x=p[x];
		}
		else
		{
			x=sdt;
			while(qwq[x]) if(chg[x]) v[++cnt].push_back(x),bel[x]=cnt,qwq[x]=0,x=p[x];
			else
			{
				++cnt;
				while(qwq[x]&&!chg[x]) v[cnt].push_back(x),bel[x]=cnt,qwq[x]=0,x=p[x];
			}
		}
	}
	for(int i=1; i<=cnt; ++i) tp[i]=0;
	for(int i=1; i<=n; ++i) if(bel[i]!=bel[p[i]]) tp[bel[i]]=bel[p[i]];
	for(int i=1; i<=cnt; ++i) (!tp[i])&&(tp[i]=i);
	for(int i=1; i<=m; ++i) 
		if(q[i].op==2)
		{
			int x=bel[q[i].x];
			qwq[bel[q[i].x]]=1;
			while(qwq[bel[q[i].x]]) 
				opt[i].push_back(x),vis[i][x]=flg[x]=1,x=tp[x],qwq[x]=0;
		}
		else if(q[i].op==3) swap(tp[bel[q[i].x]],tp[bel[q[i].y]]);
	for(int i=1; i<=cnt; ++i) 
	{
		if(flg[i])
		{
			for(int j:v[i]) ++f[nxt[j]];
			for(int j=0; j<=n; j=nxt[j+1]) f[nxt[j+1]]+=f[j];
			ll val=0;
			for(int j=1; j<=m; ++j)
				if(q[j].op==2) (vis[j][i])&&(val+=q[j].y);  
				else if(q[j].op==1) ans[j]+=val*(f[q[j].y]-f[q[j].x]);
			for(int j:v[i]) a[j]+=val;
			for(int j=0; j<=n; j=nxt[j+1]) f[j]=0;
		}
		v[i]=vector<int>();
	}
	cnt=0;
	for(int i=1; i<=m; ++i)
		if(q[i].op==2)
		{
			for(int j:opt[i]) vis[i][j]=0;
			opt[i]=vector<int>();
		}
		else if(q[i].op==1) printf("%lld\n",ans[i]+pre[q[i].y]-pre[q[i].x]);
		else swap(p[q[i].x],p[q[i].y]);
	for(int i=1; i<=n; ++i) pre[i]=pre[i-1]+a[i];
	return ;
}
signed main()
{
	for(int i=1; i<=n; ++i) a[i]=read(),pre[i]=pre[i-1]+a[i];
	for(int i=1; i<=n; ++i) p[i]=read();
	for(int T=read(); T--;)
	{
		q[++m].op=read(),q[m].x=read(),q[m].y=read(),(q[m].op==1)&&(--q[m].x);
		if(m==B) solve(),m=0;
	}
	if(m) solve();
	return 0;
}