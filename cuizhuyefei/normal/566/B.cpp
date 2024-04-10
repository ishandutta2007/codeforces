#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
int n,cnt[N];Vi ans;
struct node{
	int b,c,ind;
	node(int B=0,int C=0,int Ind=0){b=B;c=C;ind=Ind;}
	bool operator<(const node &x)const{return ind<x.ind;}
};
set<node>Map[N];
int main() {
	read(n);rep(i,1,n*4){
		int a,b,c;read(c);read(a);read(b);
		Map[a].insert(node(b,c,i));Map[b].insert(node(a,c,i));
	}
	puts("YES");rep(i,1,n*4)cnt[i]=8;int p=0,pos=1;
	rep(t,1,4*n){
		if(!p){while(!SZ(Map[pos]))pos++;p=pos;}int u=p;p=0;
	//	printf("%d:%d %d\n",u,cnt[1],cnt[2]);
		node x=*Map[u].begin();Map[u].erase(Map[u].begin());
		cnt[u]--;cnt[x.b]--;cnt[x.c]++;ans.pb(x.ind);if(cnt[x.c]>8)p=x.c;
		Map[x.b].erase(node(u,x.c,x.ind));
	}
	per(i,SZ(ans)-1,0)printf("%d ",ans[i]);
	return 0;
}