#include<bits/stdc++.h>
#define _to e[i].to
const int N=800050,P=21,inf=998244353;
using namespace std;
int n,m,x,y,a[N],id[N],l[N],r[N],cnt,ty[N],rt,M[N];
long long ans;
struct edge{int to,nx;};
struct rmq{
	int mx[P][N],mn[P][N],ln[N],sz;
	void init(int n,int*a){sz=n,ln[0]=-1;
		for(int i=1;i<=n;i++)mx[0][i]=mn[0][i]=a[i],ln[i]=ln[i>>1]+1;
		for(int i=1;i<P;i++)for(int j=1;j<=n-(1<<i)+1;j++)
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<i-1)]),
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<i-1)]);
	}
	int gn(int x,int y){int z=ln[y-x+1];return min(mn[z][x],mn[z][y-(1<<z)+1]);}
	int gx(int x,int y){int z=ln[y-x+1];return max(mx[z][x],mx[z][y-(1<<z)+1]);}
	int chk(int x,int y){return x&&y&&gx(x,y)-gn(x,y)==y-x;}
}R;
struct graph{
	edge e[N<<1];int hd[N],S,dp[N];
	void add(int fr,int to){e[++S]=(edge){to,hd[fr]},hd[fr]=S;}
	void dfs(int k){
		int sn=0;
		for(int i=hd[k];i;i=e[i].nx)
			dfs(_to),sn++;
		if(!ty[k])ans++;
		else ans+=sn?1ll*sn*(sn-1)/2:1;
	}
}G;
struct seg{
	#define ls k<<1
	#define rs k<<1|1
	#define mid (l+r>>1)
	int tg[N<<2],mn[N<<2];
	void pshup(int k){mn[k]=min(mn[ls],mn[rs]);}
	void pshtg(int k,int p){tg[k]+=p,mn[k]+=p;}
	void pshdn(int k){pshtg(ls,tg[k]),pshtg(rs,tg[k]),tg[k]=0;}
	void add(int k,int l,int r,int x,int y,int p){
		if(y<l||x>r)return;if(r<=y&&l>=x)return pshtg(k,p);
		pshdn(k),add(ls,l,mid,x,y,p),add(rs,mid+1,r,x,y,p),pshup(k);
	}void add(int x,int y,int p){add(1,1,n,x,y,p);}
	int qry(int k=1,int l=1,int r=n,int x=1,int y=n){
		if(l==r)return l;pshdn(k);
		if(!mn[ls])return qry(ls,l,mid,x,y);
		return qry(rs,mid+1,r,x,y);
	}
}T;
struct stk{
	int a[N],tp;
	void psh(int k){a[++tp]=k;}
	int pop(){return a[tp--];};
	int top(int k=0){return a[tp-k];}
	int ept(){return !tp;}
}s1,s2,s;

void build(){
	for(int i=1;i<=n;i++){
		while(!s1.ept()&&a[s1.top()]>=a[i])T.add(s1.top(1)+1,s1.top(),a[s1.top()]),s1.pop();
		while(!s2.ept()&&a[s2.top()]<=a[i])T.add(s2.top(1)+1,s2.top(),-a[s2.top()]),s2.pop();
		T.add(s1.top()+1,i,-a[i]),s1.psh(i);
		T.add(s2.top()+1,i,a[i]),s2.psh(i);
		id[i]=++cnt,l[cnt]=r[cnt]=i;
		int nw=cnt,le=T.qry();
		while(!s.ept()&&l[s.top()]>=le){
			if(R.chk(M[s.top()],i))
				r[s.top()]=1,G.add(s.top(),nw),nw=s.pop();
			else if(R.chk(l[s.top()],i)){
				ty[++cnt]=1,l[cnt]=l[s.top()],r[cnt]=i,M[cnt]=l[nw];
				G.add(cnt,s.pop()),G.add(cnt,nw),nw=cnt;
			}else{
				G.add(++cnt,nw);
				do G.add(cnt,s.pop());
				while(!s.ept()&&!R.chk(l[s.top()],i));
				l[cnt]=l[s.top()],r[cnt]=i,G.add(cnt,s.pop()),nw=cnt;
			}
		}
		s.psh(nw),T.add(1,i,-1);
	}
	rt=s.top();
}

main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&x),scanf("%d",&a[x]);
	R.init(n,a);
	build();
	G.dfs(rt);
	printf("%lld",ans);
}