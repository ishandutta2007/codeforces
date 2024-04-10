// Problem: D. Around the World
// Contest: Codeforces - Codeforces Round #618 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1299/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
vector<pair<int,int>> e[100003];
struct lb{int d[5];}lsh[1003],t;
int trans[1003][1003],cnt,mp[32768];
bool insert(lb &A,int x)
{
    for(int i=4,tmp=16; i>=0; --i,tmp>>=1) 
        if(x&tmp)
            if(A.d[i]) x^=A.d[i]; 
            else 
            {
            	for(int j=i-1; j>=0; --j) 
            		if((x&(1<<j))&&A.d[j])
            			x^=A.d[j];
            	for(int j=4; j>i; --j)
            		if(A.d[j]&(1<<i))
            			A.d[j]^=x;
            	A.d[i]=x;
            	return 1;
            }
        else;
    return 0;
}
lb merge(lb A,lb B)
{
	for(int i=0; i<=4; ++i) 
		if(B.d[i]) if(!insert(A,B.d[i])) 
			return (lb){1,3,7,15,31};
	return A;
}
void dfs(lb cur)
{
	if(mp[cur.d[0]|(cur.d[1]<<1)|(cur.d[2]<<3)|(cur.d[3]<<6)|(cur.d[4]<<10)]) return ;
	lsh[++cnt]=cur,mp[cur.d[0]|(cur.d[1]<<1)|(cur.d[2]<<3)|(cur.d[3]<<6)|(cur.d[4]<<10)]=cnt;
	lb q=cur;
	for(int i=1; i<32; ++i) 
		if(insert(q,i))
			dfs(q),q=cur;
	return ;
}
int flg[100003],dep[100003];
bool ruined;
int xsum,xcnt;
map<pair<int,int>,bool> MP;
int dfn[100003],dc;
void dfs(int x,int fa)
{
	// if(ruined) return ;
	dfn[x]=++dc;
	for(auto y:e[x]) if(y.first!=fa)
		if(dep[y.first]==-1) 
			dep[y.first]=dep[x]^y.second,dfs(y.first,x);
		else 
		{
			if(!ruined&&dfn[x]>dfn[y.first])
				ruined=!insert(t,dep[y.first]^dep[x]^y.second);
		}
	else;
	if(flg[x]!=-1) ++xcnt,xsum^=dep[x]^flg[x];
	return ;
}
const int p=1e9+7;
int f[2][503];
signed main()
{
	int n=read(),m=read();
	dfs((lb){0,0,0,0,0});
	memset(flg,-1,sizeof(flg)),memset(dep,-1,sizeof(dep));
	for(int x,y,z; m--;)
	{
		x=read(),y=read(),z=read();
		if(x==1) flg[y]=z;
		else if(y==1) flg[x]=z;
#define PB(qwq,awa) push_back(make_pair(qwq,awa))
		else e[x].PB(y,z),e[y].PB(x,z);
	}
	for(int i=1; i<=cnt; ++i) 
		for(int j=1; j<=cnt; ++j)
			t=merge(lsh[i],lsh[j]),
			trans[i][j]=mp[t.d[0]|(t.d[1]<<1)|(t.d[2]<<3)|(t.d[3]<<6)|(t.d[4]<<10)];
	f[0][1]=1;
	int lst=1,cur=0;
	// cnt=0;
	for(int i=2; i<=n; ++i) if(dep[i]==-1)
	{
		t=(lb){0,0,0,0,0},dep[i]=0,ruined=0,xsum=xcnt=0,dfs(i,i);
		// if(ruined) puts("fk");
		if(ruined||xcnt==0) continue;
		// printf("%d\n",i);
		swap(lst,cur),memcpy(f[cur],f[lst],sizeof(f[cur]));
		int id=t.d[0]|(t.d[1]<<1)|(t.d[2]<<3)|(t.d[3]<<6)|(t.d[4]<<10);
		id=mp[id];
		assert(id);
		if(xcnt==1)
		{
			for(int i=1; i<=cnt; ++i) 
				f[cur][trans[i][id]]=(f[cur][trans[i][id]]+f[lst][i])%p;
		}
		else
		{
			assert(xcnt==2);
			for(int i=1; i<=cnt; ++i) 
				f[cur][trans[i][id]]=(f[cur][trans[i][id]]+(f[lst][i]<<1)%p)%p;
			if(insert(t,xsum))
			{
				id=t.d[0]|(t.d[1]<<1)|(t.d[2]<<3)|(t.d[3]<<6)|(t.d[4]<<10);
				id=mp[id];
				assert(id);
				for(int i=1; i<=cnt; ++i) 
					f[cur][trans[i][id]]=(f[cur][trans[i][id]]+f[lst][i])%p;
			}
		}
	}
	int ans=0;
	for(int i=1; i<=cnt; ++i) ans=(ans+f[cur][i])%p;
	printf("%d\n",ans);
	return 0;
}