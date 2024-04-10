#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
const int M=150;
int a[100004],n;
struct STbord{
	int st1[18][100004],st2[18][100004],lg[100004];
	void init(){
		for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
		for(int i=1;i<=n;i++)st1[0][i]=st2[0][i]=a[i];
		for(int i=1;i<=lg[n];i++)
			for(int j=1;j+(1<<i)-1<=n;j++)
				st1[i][j]=min(st1[i-1][j],st1[i-1][j+(1<<(i-1))]),st2[i][j]=max(st2[i-1][j],st2[i-1][j+(1<<(i-1))]);
	}
	int qry(int l,int r){
		int Lg=lg[r-l+1];
		int L=min(st1[Lg][l],st1[Lg][r-(1<<Lg)+1]),R=max(st2[Lg][l],st2[Lg][r-(1<<Lg)+1]);
		return R-L;
	}
}st;
struct LCT{
	int fa[100004],ch[100004][2],val[100004];
	stack<int>st;
	void init(){
		while(!st.empty())st.pop();
		for(int i=0;i<=n;i++)fa[i]=ch[i][0]=ch[i][1]=0,val[i]=1;
		val[0]=0;
	}
	bool get(int x){return ch[fa[x]][1]==x;}
	void pushup(int x){val[x]=val[ch[x][0]]+val[ch[x][1]]+1;}
	bool isntroot(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
	void rotate(int x){
		int y=fa[x],z=fa[y];
		bool typ=get(x);
		ch[y][typ]=ch[x][typ^1];
		if(ch[x][typ^1])fa[ch[x][typ^1]]=y;
		ch[x][typ^1]=y;
		if(isntroot(y))ch[z][get(y)]=x;
		fa[x]=z,fa[y]=x;
		pushup(y),pushup(x);
	}
	void splay(int x){
		int y=x;st.push(y);
		while(isntroot(y))y=fa[y],st.push(y);
		while(!st.empty())st.pop();
		for(int f;f=fa[x],isntroot(x);rotate(x))
			if(isntroot(f))rotate(get(x)==get(f)?f:x);
	}
	void access(int x){
		for(int y=0;x;y=x,x=fa[x])
			splay(x),ch[x][1]=y,pushup(x);
	}
	int findroot(int x){
		access(x),splay(x);
		while(1){
			if(ch[x][0])x=ch[x][0];
			else break;
		}
		splay(x);
		return x;
	}
	void link(int u,int v){
		access(u),fa[u]=v;
	}
	void cut(int u,int v){
		access(u),splay(v);
		fa[u]=ch[v][1]=0;pushup(v);
	}
}tr;
int w,q;
vector<pii>ask;
int ans[100004],ds;
int bs(int x,int w){
	int l=x,r=n+1;
	while(r>l+1){
		int mid=(l+r)>>1;
		if(st.qry(x,mid)<=w)l=mid;
		else r=mid;
	}
	return l;
}
int gotans(int x){
	int cur=1,res=0;
	while(cur!=n+1){
		int rt=tr.findroot(cur);
		res+=tr.val[rt]-1;
		if(rt==n+1)break;
		cur=bs(rt,x)+1;
		res++;
		if(cur==n+1)break;
	}
	return res;
}
int vis[100004],lst[100004];
void upd(int x,int y){
	if(vis[x])tr.cut(x,lst[x]);
	vis[x]++;
	if(vis[x]<M)tr.link(x,y),lst[x]=y;
}
vector<pii>edg[100004];
vector<pii>v[100004];
int main(){
	scanf("%d%d%d",&n,&w,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=q;i++){
		int x;scanf("%d",&x);
		ask.push_back(mkp(w-x,i));
	}
	sort(ask.begin(),ask.end());
	st.init(),tr.init();
	for(int i=1;i<=n;i++){
		int cur=i;
		for(int j=0;j<M&&cur!=n+1;j++){
			int ck=st.qry(i,cur);
			cur=bs(i,ck)+1;
			int pos=lower_bound(ask.begin(),ask.end(),mkp(ck,0))-ask.begin();
			v[pos].push_back(mkp(i,cur));
		}
	}
	for(int i=0;i<ask.size();i++){
		pii qr=ask[i];
		for(auto x:v[i])upd(x.fi,x.se);
		ans[qr.se]=gotans(qr.fi);
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]-1);
}