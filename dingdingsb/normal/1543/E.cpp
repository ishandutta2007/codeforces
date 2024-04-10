// Problem: CF1543E The Final Pursuit
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1543E
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int maxN=1<<16;
int t,n,N,m;vector<int>e[maxN];
bool vis[maxN];
int id[maxN];
int inv[maxN];
int col[maxN];
signed main(){
	read(t);
	while(t--){
		read(n);
		N=1<<n;
		m=n*(1<<n-1);
		for(int i=0;i<N;i++)
			e[i].clear(),col[i]=inv[i]=id[i]=vis[i]=0;
		for(int i=0;i<m;i++){
			int x,y;read(x,y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		queue<int>q;
		vis[0]=1;
		int kk=1;
		for(auto v:e[0])
			q.push(v),id[v]=kk,kk<<=1;
		while(q.size()){
			int u=q.front();q.pop();
			if(vis[u])continue;vis[u]=1;
			for(auto v:e[u])if(!vis[v]){
				id[v]|=id[u];
				q.push(v);
			}
		}
		for(int i=0;i<N;i++)inv[id[i]]=i;
		for(int i=0;i<N;i++)write(inv[i]),putchar(' ');putchar('\n');
		int _=n;while(_&1^1)_>>=1;if(_!=1)puts("-1");else{
			for(int i=0;i<N;i++){
				int s=0;
				for(int j=0;j<n;j++)if(i>>j&1)
					s^=j;
				col[inv[i]]=s;
			}
			for(int i=0;i<N;i++)write(col[i]),putchar(' ');putchar('\n');
		}
	}
}