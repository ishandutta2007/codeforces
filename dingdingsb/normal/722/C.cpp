// Problem: CF722C Destroying Array
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF722C
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
typedef long long ll;
const int N=1e5+100;
int n,a[N],fa[N],sz[N],val,ans[N];
bool flag[N];int p[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	assert(x!=y);
	sz[x]+=sz[y];chkmx(val,sz[x]);
	fa[y]=x;
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(sz[i]),fa[i]=i;
	for(int i=1;i<=n;i++)read(p[n-i+1]);
	for(int i=1;i<=n;i++){
		flag[p[i]]=1;chkmx(val,sz[p[i]]);
		if(flag[p[i]-1])merge(p[i],p[i]-1);
		if(flag[p[i]+1])merge(p[i],p[i]+1);
		ans[n-i]=val;
	}
	for(int i=1;i<=n;i++)write(ans[i]),putchar('\n');
}