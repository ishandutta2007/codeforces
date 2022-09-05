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
const int N = 5100000,inf=0x3f3f3f3f;
int n,q,a[N],ans[N],v[N],prime[N],len,mrk[N],b[N][8];
void getp(int n){
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
vector<Pii>que[N];
inline void modify(int p, int x){while(p<=n)umin(v[p],x),p+=p&-p;}
inline int query(int p){int r=inf;while(p)umin(r,v[p]),p-=p&-p;return r;}
int main() {
	getp(N-1);read(n);read(q);rep(i,1,n)read(a[i]);
	rep(i,1,n){
		int x=a[i];
		while(mrk[x]){
			int y=mrk[x];while(x%(1LL*y*y)==0){x/=y*y;a[i]/=y*y;}
			if(x%y==0)x/=y;
		}
	}
	rep(i,1,q){int l,r;read(l);read(r);que[l].pb(Pii(i,r));}
//	rep(i,0,N-1)rep(j,0,7)b[i][j]=inf;
	rep(i,1,n)v[i]=inf;
	int dy[1<<8|3],cnt[1<<8|3];rep(i,1,7)dy[1<<i-1]=i;
	cnt[0]=0;rep(i,1,(1<<8)-1)cnt[i]=cnt[i>>1]+(i&1);
	per(i,n,1){
		int pos[16];rep(j,0,15)pos[j]=n+1;
		int p[8],v[1<<8|3];int len=0;int x=a[i];
		while(mrk[x])p[++len]=mrk[x],x/=mrk[x];if(x>1)p[++len]=x;
	//	printf("%d:%d ",i,len);rep(j,1,len)printf("%d ",p[j]);puts("");
		v[0]=1;rep(s,1,(1<<len)-1)v[s]=v[s^(s&-s)]*p[dy[s&-s]];
		rep(s,0,(1<<len)-1){
			rep(j,0,7)if(b[v[s]][j]){
			//	printf("add %d: %d %d %d\n",i,v[s],j,len-2*cnt[s]+j);
				umin(pos[len-2*cnt[s]+j],b[v[s]][j]);
			}
			b[v[s]][len]=i;
		}
		rep(j,0,15)if(pos[j]<=n)modify(pos[j],j);//,printf("[%d %d] %d\n",i,j,pos[j]);
		rep(j,0,SZ(que[i])-1)ans[que[i][j].fi]=query(que[i][j].se);
	}
	
	rep(i,1,q)printf("%d\n",ans[i]);
	return 0;
}