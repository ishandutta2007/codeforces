// Problem: F. Digits of Number Pi
// Contest: Codeforces - Codeforces Round #325 (Div. 1)
// URL: https://codeforces.com/problemset/problem/585/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
// #define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int cnt=1;
int fail[100003],trans[100003][10];
bool ed[100003];
inline void build(char *tmp,int L,int R)
{
    int cur=1;
    for(int i=L; i<R; i++)
    {
        int s=tmp[i]-'0';
        if(trans[cur][s]==0) trans[cur][s]=++cnt;
        cur=trans[cur][s];
    }
    ed[cur]=1;
    return ;
}
inline void getfail()
{
	fail[1]=1;
	queue<int> q;
    for(int i=0; i<10; i++) 
    	if(trans[1][i]) 
    		fail[trans[1][i]]=1,q.push(trans[1][i]);
    	else
    		trans[1][i]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<10; i++) 
        	if(trans[u][i]) 
        		fail[trans[u][i]]=trans[fail[u]][i],
        		q.push(trans[u][i]);
        	else 
        		trans[u][i]=trans[fail[u]][i];
    }
    return ;
}
const int p=1e9+7;
char s[1003],sl[53],sr[53];
int N,M,a[53],f[2][53][50003];
int dfs(int x,int cur,bool flg)
{
	if(!x) return ed[cur];
	if(~f[flg][x][cur]) return f[flg][x][cur];
	int res=0;
	for(int i=0; i<=(flg?a[x]:9); ++i)
		res=(res+dfs(x-1,ed[cur]?cur:trans[cur][i],flg&&(i==a[x])))%p;
	return f[flg][x][cur]=res;
}
int main()
{
    scanf("%s",s),scanf("%s",sl),scanf("%s",sr);
    N=strlen(s),M=strlen(sl);
    for(int i=0; i+(M>>1)<=N; ++i) build(s,i,i+(M>>1));
    getfail();
    memset(f,-1,sizeof(f));
    for(int i=1; i<=M; ++i) a[i]=sl[M-i]-48;
    int Z=1;
    while(!a[Z]) a[Z++]=9;
    --a[Z];
    int A=dfs(M,1,1);
    memset(f,-1,sizeof(f));
    for(int i=1; i<=M; ++i) a[i]=sr[M-i]-48;
    int B=dfs(M,1,1);
    printf("%d\n",(p+B-A)%p);
    return 0;
}