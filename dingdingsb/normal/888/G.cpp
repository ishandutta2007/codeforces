// Problem: CF888G Xor-MST
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF888G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
//#define int long long
typedef long long ll;
const int N=2e5+100;
int n,a[N];
int root,cnt,ch[N*20][2],L[N*20],R[N*20];
#define lc ch[u][0]
#define rc ch[u][1]
void ins(int&u,int x,int dep){
	if(!u)u=++cnt;
	if(!L[u])L[u]=x;R[u]=x;
	if(dep<0)return;
	int bit=a[x]>>dep&1;
	ins(ch[u][bit],x,dep-1);
}
int qry(int u,int x,int dep){
	if(dep<0)return 0;
	int bit=a[x]>>dep&1;
	if(ch[u][bit])return qry(ch[u][bit],x,dep-1);
	else return qry(ch[u][bit^1],x,dep-1)|(1<<dep);
}
ll dfs(int u,int dep){
	if(dep<0)return 0;
	if(R[lc]&&R[rc]){
		int _=0x7f7f7f7f;
		for(int i=L[lc];i<=R[lc];i++)
			chkmn(_,qry(rc,i,dep-1));
		return dfs(lc,dep-1)+dfs(rc,dep-1)+_+(1<<dep);
	}
	if(R[lc])return dfs(lc,dep-1);
	if(R[rc])return dfs(rc,dep-1);
	return 0;
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)ins(root,i,30);
	write(dfs(root,30));
}