#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=400005;
const int M=2400005;
int a[N];
int lft[N],rgt[N];
struct sgt{
	int ls,rs,l,r,id;
}s[2*M];
int rt,P;
int PP;
vector<int> g[M];
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	if(l==r){
		s[p].ls=s[p].rs=0;
		s[p].id=a[l];
		return p;
	}
	s[p].id=++PP;
	int mid=(l+r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	g[(s[p].id<<1)].push_back((s[s[p].ls].id<<1));
	g[(s[p].id<<1)+1].push_back((s[s[p].ls].id<<1)+1);
	g[(s[p].id<<1)].push_back((s[s[p].rs].id<<1));
	g[(s[p].id<<1)+1].push_back((s[s[p].rs].id<<1)+1);
	return p;
}
void chg(int p,int l,int r,int id){
	if(s[p].l==l&&s[p].r==r){
		g[(id<<1)+1].push_back(s[p].id<<1);
		return;
	}
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) chg(s[p].ls,l,r,id);
	else if(l>mid) chg(s[p].rs,l,r,id);
	else{
		chg(s[p].ls,l,mid,id);
		chg(s[p].rs,mid+1,r,id);
	}
}
stack<int> st;
int ans[M];
int dfn[M],low[M];
int scc[M];
bool ins[M];
int cnt,len;
void tarjan(int cur){
	dfn[cur]=low[cur]=++cnt;
	ins[cur]=1;
	st.push(cur);
	for(int i=0;i<g[cur].size();i++){
		int v=g[cur][i];
		if(dfn[v]){
			if(ins[v])
				low[cur]=min(low[cur],dfn[v]);
		}
		else{
			tarjan(v);
			low[cur]=min(low[cur],low[v]);
		}
	}
	if(low[cur]==dfn[cur]){
		len++;
		while(!st.empty()){
			int x=st.top();st.pop();
			if(ans[x>>1]==-1) ans[x>>1]=x&1;
			scc[x]=len;
			ins[x]=0;
			if(x==cur) break;
		}
	}
}
bool cmpl(const int &x,const int &y){
	return lft[x]<lft[y];
}
bool cmpr(const int &x,const int &y){
	return rgt[x]<rgt[y];
}
int n,m,p,k;
int main(){
	int i,j;
	scanf("%d%d%d%d",&n,&p,&m,&k);
	for(i=1;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x<<1].push_back((y<<1)+1);
		g[y<<1].push_back((x<<1)+1);
	}
	PP=p;
	for(i=1;i<=p;i++){
		scanf("%d%d",&lft[i],&rgt[i]);
		a[i]=i;
	}
	for(i=1;i<=k;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[(x<<1)+1].push_back((y<<1));
		g[(y<<1)+1].push_back((x<<1));
	}
	sort(a+1,a+p+1,cmpl);
	rt=build(1,p);
	for(i=1;i<=p;i++){
		int L=1,R=p;
		while(R>L){
			int mid=(L+R)>>1;
			if(lft[a[mid]]<=rgt[i]) L=mid+1;
			else R=mid;
		}
		if(L>p||lft[a[L]]<=rgt[i]) continue;
		chg(rt,L,p,i);
	}
	P=0;
	sort(a+1,a+p+1,cmpr);
	rt=build(1,p);
	for(i=1;i<=p;i++){
		int L=1,R=p;
		while(R>L){
			int mid=(L+R)>>1;
			if(rgt[a[mid]]<lft[i]) L=mid+1;
			else R=mid;
		}
		if(!(R-1)||rgt[a[R-1]]>=lft[i]) continue;
		chg(rt,1,R-1,i);
	}
	memset(ans,-1,sizeof(ans));
	for(i=1;i<=PP<<1;i++)
		if(!dfn[i]) tarjan(i);
	for(i=1;i<=p;i++){
		if(scc[i<<1]==scc[(i<<1)+1]){
			printf("-1");
			return 0;
		}
	}
	int sum=0,fl=0;
	for(i=1;i<=p;i++){
		if(ans[i]==1){
			sum++;
			fl=max(fl,lft[i]);
		}
	}
	printf("%d %d\n",sum,fl);
	for(i=1;i<=p;i++) if(ans[i]==1) printf("%d ",i);
	return 0;
}