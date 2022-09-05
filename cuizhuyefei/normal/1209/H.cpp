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
const int N = 266666;
int n,id[N];
double lim,a[N],b[N],c[N],res,E,cost[N],v_space[N],v_line[N],val[N<<2],lzy[N<<2],mn[N];int len;
bool cmp(int x, int y){return c[x]<c[y];}
void space(double x){
	if(E>=x/2){E-=x/2;res+=x/2;v_space[++len]=2;}
	else{double v=x/(x-E);E=0;res+=x/v;v_space[++len]=v;}
}

void upd(int k){val[k]=min(val[k<<1],val[k<<1|1]);}
void pushdown(int k){
	if(lzy[k]){
		lzy[k<<1]+=lzy[k];val[k<<1]+=lzy[k];
		lzy[k<<1|1]+=lzy[k];val[k<<1|1]+=lzy[k];
		lzy[k]=0;
	}
}
void add(int k, int l, int r, double x, int L, int R){
	if(l==L&&r==R){val[k]+=x;lzy[k]+=x;return;}
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)add(k<<1,l,r,x,L,mid);
	else if(l>mid)add(k<<1|1,l,r,x,mid+1,R);
	else add(k<<1,l,mid,x,L,mid),add(k<<1|1,mid+1,r,x,mid+1,R);
	upd(k);
}
double qry(int k, int l, int r, int L, int R){
	if(l==L&&r==R)return val[k];
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)return qry(k<<1,l,r,L,mid);
	else if(l>mid)return qry(k<<1|1,l,r,mid+1,R);
	return min(qry(k<<1,l,mid,L,mid),qry(k<<1|1,mid+1,r,mid+1,R));
}
void ck(double x, double c, double v){
	E-=x-(c+1)*x/(v+c);
	cerr<<"E="<<E<<endl;
	assert(E>=-1e-8);
}
int main() {
	read(n);scanf("%lf",&lim);
	rep(i,1,n)scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
	rep(i,1,n)mn[i]=1e18;
	rep(i,1,n){
		space(a[i]-b[i-1]);umin(mn[i-1],E);
		E+=(b[i]-a[i])/c[i];cost[i]=(b[i]-a[i])/c[i];
		umin(mn[i],E);
	}
	space(lim-b[n]);umin(mn[n],E);
	rep(i,1,n)add(1,i,i,mn[i],1,n);
	rep(i,1,n)id[i]=i;sort(id+1,id+n+1,cmp);
//	printf("qwq %.11lf %.11lf\n",res,E);
	rep(tt,1,n){
		int i=id[tt];double E=qry(1,i,n,1,n)-(b[i]-a[i])/c[i];
		add(1,i,n,-(b[i]-a[i])/c[i],1,n);
		if((b[i]-a[i])/(2+c[i])<=E){
			add(1,i,n,-(b[i]-a[i])/(2+c[i]),1,n);cost[i]=(b[i]-a[i])/(2+c[i]);v_line[i]=2;
		}
		else{
			assert(b[i]-a[i]-E!=0);
			double v=(c[i]+1)*(b[i]-a[i])/(b[i]-a[i]-E)-c[i];
			add(1,i,n,-E,1,n);
		//	assert(v>=-1e-7&&v<=2+1e-7);
			cost[i]=(b[i]-a[i])/(v+c[i]);E=0;v_line[i]=v;
		//	cerr<<tt<<' '<<v<<endl;
		}
	}
	rep(i,1,n)res+=cost[i];printf("%.11lf\n",res);
	return 0;
}