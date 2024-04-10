// Problem: C. Web of Lies
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/C
// Memory Limit: 256 MB
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
int n,m;int deg[N];int ans;
void add(int u,int v){
	if(u>v)swap(u,v);
	ans-=deg[u]==0;
	deg[u]++;
}
void del(int u,int v){
	if(u>v)swap(u,v);
	deg[u]--;
	ans+=deg[u]==0;
}
signed main(){
	read(n,m);ans=n;
	for(int i=1;i<=m;i++){
		int u,v;read(u,v);add(u,v);
	}
	int q;read(q);
	while(q--){
		int op,u,v;read(op);
		if(op==1)read(u,v),add(u,v);
		else if(op==2)read(u,v),del(u,v);
		else write(ans),putchar('\n');
	}
}