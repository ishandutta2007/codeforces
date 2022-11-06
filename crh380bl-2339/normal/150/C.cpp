#include<cstdio>

const int maxn=150000+5;
const int maxm=300000+5;

int x[maxn],p[maxn],on[maxm],off[maxm];

double a[maxn];
struct node{
	double s,sl,sr,sx;
	node(){};
	node(double as,double asl,double asr,double asx):
	s(as),sl(asl),sr(asr),sx(asx)
	{};
};
double sum[maxn<<2],suml[maxn<<2],sumr[maxn<<2],sumx[maxn<<2];
inline double max(double x,double y){
	return x>y?x:y;
}

void pushup(int rt){
	int ls=rt<<1,rs=ls|1;
	suml[rt]=max(suml[ls],suml[rs]+sum[ls]);
	sumr[rt]=max(sumr[rs],sumr[ls]+sum[rs]);
	sumx[rt]=max(max(sumx[ls],sumx[rs]),sumr[ls]+suml[rs]);
	sum[rt]=sum[ls]+sum[rs];
}
void build(int rt,int l,int r){
	if(l==r){
		sum[rt]=suml[rt]=sumr[rt]=sumx[rt]=a[l];
		return;
	}
	int ls=rt<<1,rs=ls|1;
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(rt);
}
node que(int rt,int l,int r,int tl,int tr){
//	printf("%d %d %d %d %d\n",rt,l,r,tl,tr);
	if(tl==l&&r==tr){
		return node(sum[rt],suml[rt],sumr[rt],sumx[rt]);
	}
	int ls=rt<<1,rs=ls|1;
	int mid=(l+r)>>1;
	if(tr<=mid)return que(ls,l,mid,tl,tr);
	if(tl>mid)return que(rs,mid+1,r,tl,tr);
	
	node ln=que(ls,l,mid,tl,mid);
	node rn=que(rs,mid+1,r,mid+1,tr);
	node re;
	re.sl=max(ln.sl,ln.s+rn.sl);
	re.sr=max(rn.sr,ln.sr+rn.s);
	re.s=ln.s+rn.s;
	re.sx=max(max(ln.sx,rn.sx),ln.sr+rn.sl);
	return re;
}

int main(){
	int n,m,c;
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=n;i++)scanf("%d",&x[i]);
	for(int i=2;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&on[i],&off[i]);
	}
	for(int i=2;i<=n;i++){
		a[i]=1.0*(x[i]-x[i-1])/2.0-((1.0*p[i]/100.0)*c);
	}
	build(1,1,n);
	double ass=0.0;
	for(int i=1;i<=m;i++){
		node re=que(1,1,n,on[i]+1,off[i]);
		ass+=max(0.0,re.sx);
	}
	printf("%.10lf",ass);
	return 0;
}