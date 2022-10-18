#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
const int MX=100011;
int n,m,q;
int a[MX][11];
struct Seg{
	int s,no[2][11];
}sg[262333];

int fa[MX];
inline int ffa(int k){return k==fa[k]?k:(fa[k]=ffa(fa[k]));}
Seg psup(Seg x,Seg y,int mid){
	int Cx=0;
	for(int i=1;i<=n;i++)fa[x.no[0][i]]=x.no[0][i],Cx=max(Cx,x.no[0][i]);
	for(int i=1;i<=n;i++)fa[x.no[1][i]]=x.no[1][i],Cx=max(Cx,x.no[1][i]);
	for(int i=1;i<=n;i++)y.no[0][i]+=Cx,y.no[1][i]+=Cx;
	for(int i=1;i<=n;i++)fa[y.no[0][i]]=y.no[0][i];
	for(int i=1;i<=n;i++)fa[y.no[1][i]]=y.no[1][i];
	int C=0;
	for(int i=1;i<=n;i++)if(a[mid][i]==a[mid+1][i]){
		int fx=ffa(y.no[0][i]),fy=ffa(x.no[1][i]);
		if(fx!=fy)++C,fa[fx]=fy;
	}
	Seg res;
	for(int i=1;i<=n;i++)res.no[0][i]=ffa(x.no[0][i]),res.no[1][i]=ffa(y.no[1][i]);
	res.s=x.s+y.s-C;
	int tc=0;
	for(int i=1;i<=n;i++){
		if(res.no[0][i]>0){
			int tv=res.no[0][i];--tc;
			for(int j=1;j<=n;j++)if(res.no[0][j]==tv)res.no[0][j]=tc;
			for(int j=1;j<=n;j++)if(res.no[1][j]==tv)res.no[1][j]=tc;
		}
		if(res.no[1][i]>0){
			int tv=res.no[1][i];--tc;
			for(int j=1;j<=n;j++)if(res.no[0][j]==tv)res.no[0][j]=tc;
			for(int j=1;j<=n;j++)if(res.no[1][j]==tv)res.no[1][j]=tc;
		}
	}
	for(int i=1;i<=n;i++)res.no[0][i]=-res.no[0][i],res.no[1][i]=-res.no[1][i];
	return res;
}
void build(int no,int l,int r){
	if(l==r){
		int C=0;
		for(int i=1;i<=n;i++)sg[no].no[0][i]=sg[no].no[1][i]=((i>1&&a[l][i]==a[l][i-1])?sg[no].no[0][i-1]:++C);
		sg[no].s=C;
	}else{
		int mid=(l+r)>>1;
		build(no<<1,l,mid),build(no<<1|1,mid+1,r);
		sg[no]=psup(sg[no<<1],sg[no<<1|1],mid);
	}
}
Seg que(int no,int l,int r,int ll,int rr){
	if(ll<=l&&rr>=r)return sg[no];
	else{
		int mid=(l+r)>>1;
		if(rr<=mid)return que(no<<1,l,mid,ll,rr);
		else if(ll>mid)return que(no<<1|1,mid+1,r,ll,rr);
		else return psup(que(no<<1,l,mid,ll,rr),que(no<<1|1,mid+1,r,ll,rr),mid);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)scanf("%d",&a[j][i]);
	build(1,1,m);
	for(int i=1;i<=q;i++){
		int l,r;scanf("%d%d",&l,&r);
		printf("%d\n",que(1,1,m,l,r).s);
	}
	return 0;
}