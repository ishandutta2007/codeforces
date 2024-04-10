#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<string>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
const int N = 433333,inf=0x3f3f3f3f;
int n,q,a[N],ans[N];
struct zkw{
	int m,a[N<<2];
	inline void init(int n){
		for(m=1;m<=n+1;m<<=1);
		rep(i,0,m+m)a[i]=inf;
	}
	inline void modify(int p, int x){
		a[m+p]=x;for(int i=m+p>>1;i;i>>=1)a[i]=min(a[i<<1],a[i<<1|1]);
	}
	inline int query(int l, int r){
		l=m+l-1;r=m+r+1;int res=inf;
		while((l>>1)!=(r>>1)){
			if(!(l&1))res=min(res,a[l+1]);
			if(r&1)res=min(res,a[r-1]);l>>=1;r>>=1;
		}
		return res;
	}
}ori,hz1,hz2,qz1,qz2,qz3,qz4;
struct yzr{
	int a[N],id[N],x0[N],y0[N],x1[N],y1[N],len,sta[N],top;
	Vi h1[N],h2[N],q1[N],q2[N];
	inline int Abs(int x){return x>0?x:-x;}
	inline int findpos(int x){//sta[i]>=x
		int l=1,r=top;if(sta[top]<x)return top+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(sta[mid]>=x)r=mid;else l=mid+1;
		}
		return l;
	}
	inline int findval(int x){//a[sta[i]]>=x
		int l=1,r=top;if(a[sta[top]]<x)return top+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[sta[mid]]>=x)r=mid;else l=mid+1;
		}
		return l;
	}
	inline void Solve(){
		ori.init(n);rep(i,1,n)ori.modify(i,a[i]);
		rep(i,1,len){
			ans[id[i]]=1+x1[i]-x0[i]+y1[i];int l=x0[i],r=x1[i];
			int mn=min(y0[i],ori.query(l,r));
			ans[id[i]]=min(ans[id[i]],r-l+Abs(mn-y1[i]));
			if(mn>y1[i]){
			//	mn=inf;rep(j,r,n)mn=min(mn,a[j]),ans[id[i]]=min(ans[id[i]],Abs(mn-y1[i])+r-l+2*(j-r));
				h1[r].pb(i);
			//	mn=inf;per(j,l,1)mn=min(mn,a[j]),ans[id[i]]=min(ans[id[i]],Abs(mn-y1[i])+r-l+2*(l-j));
				q1[l].pb(i);
			}
		//	mn=inf;rep(j,r,n)mn=min(mn,a[j]),ans[id[i]]=min(ans[id[i]],1+r-l+2*(j-r)+Abs(mn-y1[i]));
			h2[r].pb(i);
		//	mn=inf;per(j,r,1)mn=min(mn,a[j]),ans[id[i]]=min(ans[id[i]],1+r-l+(j<=l?2*(l-j):0)+Abs(mn-y1[i]));
			q2[r].pb(i);
		}
		top=0;hz1.init(n);hz2.init(n);
		per(i,n,1){
			while(top&&a[sta[top]]>=a[i])top--;
			sta[++top]=i;hz1.modify(top,2*i+a[i]);hz2.modify(top,2*i-a[i]);
			rep(j,0,SZ(h1[i])-1){
				int p=h1[i][j],p2=findval(y1[p]),l=x0[p],r=x1[p];
				//Abs(a[pos]-y1[p])+r-l+2*(pos-r)
				if(p2<=top)ans[id[p]]=min(ans[id[p]],-y1[p]+r-l-2*r+hz1.query(p2,top));
				if(1<=p2-1)ans[id[p]]=min(ans[id[p]],y1[p]+r-l-2*r+hz2.query(1,p2-1));
			}
			rep(j,0,SZ(h2[i])-1){
				int p=h2[i][j],p2=findval(y1[p]),l=x0[p],r=x1[p];
				//Abs(a[pos]-y1[p])+r-l+2*(pos-r)
				if(p2<=top)ans[id[p]]=min(ans[id[p]],1-y1[p]+r-l-2*r+hz1.query(p2,top));
				if(1<=p2-1)ans[id[p]]=min(ans[id[p]],1+y1[p]+r-l-2*r+hz2.query(1,p2-1));
			}
		}
		top=0;qz1.init(n);qz2.init(n);qz3.init(n);qz4.init(n);
		rep(i,1,n){
			while(top&&a[sta[top]]>=a[i])top--;
			sta[++top]=i;
			qz1.modify(top,a[i]);
			qz2.modify(top,-2*i-a[i]);
			qz3.modify(top,a[i]-2*i);
			qz4.modify(top,-a[i]);
			rep(j,0,SZ(q2[i])-1){
				int p=q2[i][j],p1=findpos(x0[p]),p2=findval(y1[p]),l=x0[p],r=x1[p];
				if(max(p1,p2)<=top)ans[id[p]]=min(ans[id[p]],1+r-l-y1[p]+qz1.query(max(p1,p2),top));//1+r-l+a[pos]-y1[p]
				if(min(p1-1,p2-1)>=1)ans[id[p]]=min(ans[id[p]],1+r-l+2*(x0[p])+y1[p]+qz2.query(1,min(p1-1,p2-1)));//1+r-l+2*(x0[p]-pos)+y1[p]-a[pos]
				if(p1-1>=p2)ans[id[p]]=min(ans[id[p]],1+r-l+2*(x0[p])-y1[p]+qz3.query(p2,p1-1));//1+r-l+2*(x0[p]-pos)+a[pos]-y1[p]
				if(p2-1>=p1)ans[id[p]]=min(ans[id[p]],1+r-l+y1[p]+qz4.query(p1,p2-1));//1+r-l+y1[p]-a[pos]
			}
			rep(j,0,SZ(q1[i])-1){
				int p=q1[i][j],p2=findval(y1[p]),l=x0[p],r=x1[p];
				//Abs(a[pos]-y1[p])+r-l+2*(l-pos)
				if(p2<=top)ans[id[p]]=min(ans[id[p]],qz3.query(p2,top)-y1[p]+r-l+2*l);
				if(1<=p2-1)ans[id[p]]=min(ans[id[p]],qz2.query(1,p2-1)+y1[p]+r-l+2*l);
			}
		}
	}
}x,y;
int main() {

	read(n);rep(i,1,n)read(a[i]);
	rep(i,1,n)x.a[i]=a[i],y.a[i]=a[n-i+1];
	read(q);
	rep(i,1,q){
		int x0,y0,x1,y1;read(x0);read(y0);read(x1);read(y1);
		if(x0<=x1)x.len++,x.x0[x.len]=x0,x.y0[x.len]=y0,x.x1[x.len]=x1,x.y1[x.len]=y1,x.id[x.len]=i;
		else{x0=n-x0+1;x1=n-x1+1;y.len++,y.x0[y.len]=x0,y.y0[y.len]=y0,y.x1[y.len]=x1,y.y1[y.len]=y1;y.id[y.len]=i;}
	}
	x.Solve();y.Solve();
	rep(i,1,q)printf("%d\n",ans[i]);
	return 0;
}