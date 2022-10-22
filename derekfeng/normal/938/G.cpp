#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii; 
#define fi first
#define se second
#define mkp make_pair
int n,m,q;
map<pii,int>mp,tim;
pii qry[200004];
vector<piii>g[524300];
void updqry(int l,int r,int id,int a,int b,piii x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		g[id].push_back(x);
		return; 
	}
	int mid=(l+r)>>1;
	updqry(l,mid,id<<1,a,b,x),updqry(mid+1,r,id<<1|1,a,b,x);
}
int bas[30];
void ins(int x){
	for(int i=29;~i;i--)if((1<<i)&x){
		if(!bas[i]){
			bas[i]=x;
			break;
		}
		x^=bas[i];
	}
}
int f[200004],xorsum[200004],dep[200004];
stack<piii>st;
pii F(int x){
	int res=0;
	while(f[x]!=x)res^=xorsum[x],x=f[x];
	return mkp(x,res);
}
void merge(int x,int y,int d){
	if(dep[x]>dep[y])swap(x,y);
	st.push(mkp(mkp(x,y),dep[y]));
	dep[y]=max(dep[y],dep[x]+1);
	xorsum[x]=d,f[x]=y;
}
void solsegtree(int l,int r,int id){
	int bas1[30];
	for(int i=0;i<30;i++)bas1[i]=bas[i];
	int cur=st.size();
	for(auto x:g[id]){
		int u=x.fi.fi,v=x.fi.se,d=x.se;
		pii uu=F(u),vv=F(v);
		if(uu.fi!=vv.fi)merge(uu.fi,vv.fi,d^uu.se^vv.se);
		else ins(uu.se^vv.se^d);
	}
	if(l!=r){
		int mid=(l+r)>>1;
		solsegtree(l,mid,id<<1),solsegtree(mid+1,r,id<<1|1);
	}else if(qry[l].fi!=0){
		int u=qry[l].fi,v=qry[l].se;
		pii uu=F(u),vv=F(v);
		int ans=uu.se^vv.se;
		for(int i=29;~i;i--)if(ans>(ans^bas[i]))ans^=bas[i];
		printf("%d\n",ans);
	}
	for(int i=0;i<30;i++)bas[i]=bas1[i];
	while(st.size()>cur){
		piii x=st.top();st.pop();
		xorsum[x.fi.fi]=0,f[x.fi.fi]=x.fi.fi;
		dep[x.fi.se]=x.se;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,d;scanf("%d%d%d",&u,&v,&d);
		if(u>v)swap(u,v); 
		mp[mkp(u,v)]=d;
		tim[mkp(u,v)]=1;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int op,x,y,d;
		scanf("%d%d%d",&op,&x,&y);
		if(x>y)swap(x,y);
		if(op==1){
			scanf("%d",&d);
			mp[mkp(x,y)]=d,tim[mkp(x,y)]=i;
		}
		if(op==2){
			int times=tim[mkp(x,y)],len=mp[mkp(x,y)];
			updqry(1,q,1,times,i-1,mkp(mkp(x,y),len));
			tim[mkp(x,y)]=0;
		}
		if(op==3)qry[i]=mkp(x,y);
	}
	for(int i=1;i<=n;i++)f[i]=i;
	for(auto it=tim.begin();it!=tim.end();it++)if((it->second)!=0)
		updqry(1,q,1,it->second,q,mkp(it->first,mp[(it->first)]));
	solsegtree(1,q,1);
}