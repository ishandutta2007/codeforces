#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1020;
int k,n,res,p[N],top,NOW;bool ok,gg[N];Vi rec;
struct dot{
	int x,y;dot(int X=0,int Y=0){x=X;y=Y;}
}a[N],b[N];Vi c[8][N];
inline ll Cross(dot a, dot b){return 1LL*a.x*b.y-1LL*a.y*b.x;}
dot operator-(dot a, dot b){return dot(a.x-b.x,a.y-b.y);}
inline bool onseg(dot p, dot a, dot b){
	return p.x>=min(a.x,b.x)&&p.x<=max(a.x,b.x)&&p.y>=min(a.y,b.y)&&p.y<=max(a.y,b.y)&&Cross(a-p,b-p)==0;
}
bool ck(int tar){
	if(!top)return 0;
	int from=p[top--];
	rep(i,0,SZ(c[from][tar])-1)if(!gg[c[from][tar][i]]){
		if(!ck(c[from][tar][i]))return 0;
	}
	gg[tar]=1;rec.pb(tar);return 1;
}
void dfs(int dep, int used){
	if(ok)return;
	if(dep>k){
		/*if(NOW==4){
			cerr<<p[1]<<' '<<p[2]<<endl;
		}*/
		top=k;ok|=ck(NOW);rep(i,0,SZ(rec)-1)gg[rec[i]]=0;rec.clear();
		return;
	}
	rep(i,1,k)if(!(used>>i-1&1))p[dep]=i,dfs(dep+1,used|(1<<i-1));
}
int main() {//freopen("1.in","r",stdin);
	read(k);read(n);
	rep(i,1,k)read(a[i].x),read(a[i].y);
	rep(i,1,n)read(b[i].x),read(b[i].y);
	rep(i,1,k)rep(j,1,n)rep(k,1,n)if(j!=k&&onseg(b[k],b[j],a[i]))
		c[i][j].pb(k);
	for(NOW=1;NOW<=n;NOW++){
		ok=0;dfs(1,0);res+=ok;//if(ok)cerr<<NOW<<endl;
	}
	cout<<res;
	return 0;
}