#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 333333;
int n,k,f[N],res,col[N],c0[N],c1[N];Vi dot[N];char s[N];
bool qd[N];
Vi pos[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void qinding(int x, int c){
	int fx=find(x);if(qd[fx])return;
//	printf("qinding %d %d\n",x,c);
	qd[fx]=1;if(col[x]==c){res-=min(c0[fx],c1[fx]);res+=c1[fx];return;}
	res-=min(c0[fx],c1[fx]);
	c0[fx]=c1[fx]=0;
	for(int y:dot[fx]){
		col[y]^=1,res+=col[y],c0[fx]+=col[y]==0,c1[fx]+=col[y]==1;
	//	printf("%d-->%d\n",y,col[y]);
	}
}
void merge(int x, int y, int c){
	int fx=find(x),fy=find(y);
	if(fx==fy)return;if(SZ(dot[fx])>SZ(dot[fy]))swap(fx,fy),swap(x,y);
	if(qd[fx]&&!qd[fy])qinding(y,col[x]^c);
	if(!qd[fx]&&qd[fy])qinding(x,col[y]^c);
	if(col[x]^col[y]^c){
		assert(!qd[fx]);
		swap(c0[fx],c1[fx]);
		for(int q:dot[fx])col[q]^=1;
	}
	assert((col[x]^col[y]^c)==0);
	if(!qd[fy])res-=min(c0[fx],c1[fx])+min(c0[fy],c1[fy]);
	f[fx]=fy;qd[fy]|=qd[fx];c0[fy]+=c0[fx];c1[fy]+=c1[fx];
	if(!qd[fy])res+=min(c0[fy],c1[fy]);
	for(int ss:dot[fx])dot[fy].pb(ss);dot[fx].clear();
//	printf("merge %d %d %d %d %d (%d %d)\n",x,y,c,fx,fy,c0[fy],c1[fy]);
}
int main() {
	read(n);read(k);scanf("%s",s+1);
	rep(i,1,k){
		int sz,x;read(sz);
		rep(j,1,sz)read(x),pos[x].pb(i);
	}
	rep(i,1,k)f[i]=i,dot[i].pb(i),c0[i]=1;
	rep(i,1,n){
		if(SZ(pos[i])==2){
			merge(pos[i][0],pos[i][1],s[i]=='0');
		}
		else if(SZ(pos[i])==1){
			qinding(pos[i][0],s[i]=='0');
		}
		printf("%d\n",res);
	}
	return 0;
}