// Problem: CF527E Data Center Drama
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF527E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=1e5+10,M=8e5+10;
int n,m;int deg[N],tot=1;
struct node{int v,nxt;bool vis;}e[M];
int head[N];
void add(int x,int y){
	deg[x]++,deg[y]++;
	e[++tot]={y,head[x],0};head[x]=tot;
	e[++tot]={x,head[y],0};head[y]=tot;
}
int k=0;
void dfs(int x){
	for(int&i=head[x];i;i=e[i].nxt)if(!e[i].vis){
		e[i].vis=e[i^1].vis=1;int y=e[i].v;
		dfs(y);
		if((++k)&1)write(x),putchar(' '),write(y),putchar('\n');
		else write(y),putchar(' '),write(x),putchar('\n');
	}
}
vector<int>v;
signed main(){
	//freopen("1.out","w",stdout);
	read(n,m);
	for(int i=1;i<=m;i++){
		int x,y;
		read(x,y);
		add(x,y);
	}
	for(int i=1;i<=n;i++)if(deg[i]&1)v.push_back(i);
	assert(v.size()%2==0);
	for(int i=0;i<v.size();i+=2)m++,add(v[i],v[i+1]);
	if(m&1)m++,add(1,1);
	write(m);putchar('\n');dfs(1);
}