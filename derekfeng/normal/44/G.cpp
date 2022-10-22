#include<bits/stdc++.h>
using namespace std;
struct P{
	int x,y,id;
}p[100004];
bool cmp1(P A,P B){
	return A.x<B.x;
}
bool cmp2(P A,P B){
	return A.y<B.y;
}
int son[2][100004],L[100004],R[100004],D[100004],U[100004],Mn[100004],inv[100004],fa[100004];
void maintain(int i){
	int ls=son[0][i],rs=son[1][i];
	L[i]=R[i]=p[i].x,D[i]=U[i]=p[i].y,Mn[i]=p[i].id;
	if(ls)L[i]=min(L[i],L[ls]),R[i]=max(R[i],R[ls]),D[i]=min(D[i],D[ls]),U[i]=max(U[i],U[ls]),Mn[i]=min(Mn[i],Mn[ls]);
	if(rs)L[i]=min(L[i],L[rs]),R[i]=max(R[i],R[rs]),D[i]=min(D[i],D[rs]),U[i]=max(U[i],U[rs]),Mn[i]=min(Mn[i],Mn[rs]);
}
int built(int l,int r,bool D,int par){
	if(l>r)return 0;
	int md=(l+r)>>1;
	fa[md]=par;
	if(D)nth_element(p+l,p+md,p+r+1,cmp1);
	else nth_element(p+l,p+md,p+r+1,cmp2);
	if(l<md)son[0][md]=built(l,md-1,D^1,md);
	if(md<r)son[1][md]=built(md+1,r,D^1,md);
	maintain(md);
	inv[p[md].id]=md;
	return md;
}
void upd(int i){
	if(!i)return;
	Mn[i]=p[i].id;
	int ls=son[0][i],rs=son[1][i];
	if(ls)Mn[i]=min(Mn[i],Mn[ls]);
	if(rs)Mn[i]=min(Mn[i],Mn[rs]);
	upd(fa[i]);
}
int n,m,ans[100004];
int a[100004],b[100004],c[100004],d[100004],h[100004];
vector<int>ord;
bool cmp3(int a,int b){
	return h[a]<h[b];
}
int qry(int l,int r,int L1,int R1,int D1,int U1){
	int md=(l+r)>>1;
	if(R1<L[md]||L1>R[md]||U1<D[md]||D1>U[md]||Mn[md]==1e9)return 1e9;
	if(L1<=L[md]&&R[md]<=R1&&D1<=D[md]&&U[md]<=U1)return Mn[md];
	int ret=1e9;
	if(L1<=p[md].x&&p[md].x<=R1&&D1<=p[md].y&&p[md].y<=U1)ret=p[md].id;
	if(l<md)ret=min(ret,qry(l,md-1,L1,R1,D1,U1));
	if(md<r)ret=min(ret,qry(md+1,r,L1,R1,D1,U1));
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d%d",&a[i],&b[i],&c[i],&d[i],&h[i]);
		ord.push_back(i);
	}
	sort(ord.begin(),ord.end(),cmp3);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&p[i].x,&p[i].y),p[i].id=i;
	built(1,m,1,0);
	for(auto x:ord){
		int qr=qry(1,m,a[x],b[x],c[x],d[x]);
		if(qr==1e9)continue;
		ans[qr]=x;
		int tmp=inv[qr];
		p[tmp].id=1e9,upd(tmp);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}