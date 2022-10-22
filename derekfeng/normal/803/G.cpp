#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,K,st[19][100004],lg[100004],q;
int cnt,lzy[6000004],mn[6000004],s[2][6000004],rt;
int qry(int l,int r){
	int Lg=lg[r-l+1];
	return min(st[Lg][l],st[Lg][r-(1<<Lg)+1]);
}
int w(int l,int r){
	int len=r-l+1;
	if(len>=n)return qry(0,n-1);
	int st=l%n;
	if(st+len<=n)return qry(st,st+len-1);
	return min(qry(st,n-1),qry(0,r%n));
}
int range(int l,int r,int a,int b){
	int L=max(l,a),R=min(r,b);
	return w(L,R);
}
int push(int id,int x){
	if(!id)id=++cnt;
	lzy[id]=mn[id]=x;
	return id;
}
void pushdown(int id){
	if(lzy[id]){
		s[0][id]=push(s[0][id],lzy[id]);
		s[1][id]=push(s[1][id],lzy[id]);
		lzy[id]=0;
	}
}
void pushup(int id,int l,int mid,int r){
	mn[id]=1e9;
	if(s[0][id])mn[id]=mn[s[0][id]];
	else mn[id]=w(l,mid);
	if(s[1][id])mn[id]=min(mn[id],mn[s[1][id]]);
	else mn[id]=min(mn[id],w(mid+1,r));
}
int ins(int id,int l,int r,int a,int b,int x){
	if(r<a||b<l)return id;
	if(!id)id=++cnt;
	if(a<=l&&r<=b){
		push(id,x);
		return id;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	s[0][id]=ins(s[0][id],l,mid,a,b,x),s[1][id]=ins(s[1][id],mid+1,r,a,b,x);
	pushup(id,l,mid,r);
	return id;
}
int got(int id,int l,int r,int a,int b){
	if(r<a||b<l)return 1e9;
	if(!id)return range(l,r,a,b);
	if(a<=l&&r<=b)return mn[id];
	pushdown(id);
	int mid=(l+r)>>1;
	return min(got(s[0][id],l,mid,a,b),got(s[1][id],mid+1,r,a,b));
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=0;i<n;i++)scanf("%d",&st[0][i]);
	for(int i=1;i<=lg[n];i++)for(int j=0;j+(1<<i)<=n;j++)
		st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	scanf("%d",&q);
	while(q--){
		int op,l,r,x;scanf("%d%d%d",&op,&l,&r);l--,r--;
		if(op==1)scanf("%d",&x),rt=ins(rt,0,n*K-1,l,r,x);
		else printf("%d\n",got(rt,0,n*K-1,l,r));
	}
}