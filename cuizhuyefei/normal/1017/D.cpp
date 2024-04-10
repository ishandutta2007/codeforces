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
const int N = 1020000,M=5000;
int cnt[M],w[N],n,m,q,f[666],val[M],ans[N];char S[15];
struct query{int v,k,ind;}que[N];
bool cmp(query a, query b){
	return a.v<b.v;
}
int main() {
	read(n);read(m);read(q);
	rep(i,1,n)read(w[i]);
	rep(i,1,m){
		scanf("%s",S+1);int v=0;rep(j,1,n)v=v*2+(S[j]=='1');cnt[v]++;
	}
	rep(i,1,q){
		scanf("%s",S+1);int v=0;rep(j,1,n)v=v*2+(S[j]=='1');
		que[i].v=v;read(que[i].k);que[i].ind=i;
	}
	rep(i,0,(1<<n)-1){//val[i]
		rep(j,0,n-1)val[i]+=((i>>j)&1)?w[n-j]:0;
	}
	sort(que+1,que+q+1,cmp);int all=(1<<n)-1;
//	rep(i,0,all)printf("cnt[%d]=%d, %d\n",i,cnt[i],val[i]);
	rep(l,1,q){
		int r;for(r=l;r<=q;r++)if(que[r].v!=que[l].v)break;
		memset(f,0,sizeof(f));
		rep(i,0,(1<<n)-1){
			int x=val[(i&que[l].v)|((all^i)&(all^que[l].v))];if(x<=100)f[x]+=cnt[i];
		}
		rep(i,1,100)f[i]+=f[i-1];
		rep(i,l,r-1)ans[que[i].ind]=f[que[i].k];
		l=r-1;
	}
	rep(i,1,q)printf("%d\n",ans[i]);
	return 0;
}