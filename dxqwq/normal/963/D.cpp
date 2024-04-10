// Problem: D. Frequency of String
// Contest: Codeforces - Tinkoff Internship Warmup Round 2018 and Codeforces Round #475 (Div. 1)
// URL: https://codeforces.com/contest/963/problem/D
// Memory Limit: 512 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
int n,cnt=0;
char tmp[1000003];
pair<int,int> q[1000003];
set<int> pos[1000003];
int fail[1000003],trans[1000003][26];
int ans[1000003],sz[1000003];
vector<int> id[1000003],e[1000003];
void solve(pair<int,int> &q,set<int> &p)
{
	int D=q.first,id=q.second;
	int N=(int)p.size();
	// printf("%d %d %d\n",id,D,N);
	// for(int i:p) printf("%d ",i);
	// puts("");
	if(N<D) return ;
	vector<int> tp;
	for(int i:p) tp.push_back(i);
	ans[id]=0x3f3f3f3f;
	for(int i=0; i+D<=N; ++i)
		ans[id]=min(ans[id],tp[i+D-1]-tp[i]);
	return ;
}
inline void build(int I,int J)
{
    int len=strlen(tmp);
    int cur=0;
    for(int i=0; i<len; i++)
    {
        int s=tmp[i]-'a';
        if(trans[cur][s]==0) trans[cur][s]=++cnt;
        cur=trans[cur][s];
    }
    sz[J]=len;
    q[cur]=make_pair(I,J);
    return ;
}
inline void getfail()
{
	fail[0]=0;
	queue<int> q;
    for(int i=0; i<26; i++) if(trans[0][i]) fail[trans[0][i]]=0,e[0].push_back(trans[0][i]),q.push(trans[0][i]);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<26; i++) 
        	if(trans[u][i]) fail[trans[u][i]]=trans[fail[u]][i],e[trans[fail[u]][i]].push_back(trans[u][i]),q.push(trans[u][i]);
        	else trans[u][i]=trans[fail[u]][i];
    }
    return ;
}
char s[1000003];
void merge(set<int> &X,set<int> &Y)
{
	if(X.size()<Y.size()) swap(X,Y);
	for(int i:Y) X.insert(i);
	Y.clear();
	return ;
}
void dfs(int x)
{
	for(int y:e[x])
	{
		dfs(y);
		merge(pos[x],pos[y]);
	}
	if(q[x]!=make_pair(0,0)&&!pos[x].empty())
		solve(q[x],pos[x]);
}
signed main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int T=read();
	for(int i=1,tgt; i<=T; ++i)
		tgt=read(),scanf("%s",tmp),build(tgt,i);
	getfail();
	int cur=0;
	for(int i=1; i<=n; ++i)
	{
		cur=trans[cur][s[i]-'a'];
		pos[cur].insert(i);
	}
	memset(ans,-1,sizeof(ans));
	dfs(0);
	for(int i=1; i<=T; ++i) 
	if(ans[i]!=-1) printf("%d\n",ans[i]+sz[i]);
	else puts("-1");
	return 0;
}