#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=50005;

int n,m,mdn;
long long k;
int s[maxn];

struct mat{
	int v[2][2];
};

struct vec{
	int v[2];//v[0]=cur v[1]=last
};
mat operator*(const mat&a,const mat&b){
	mat c;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++){
		c.v[i][j]=(a.v[i][0]*(long long)b.v[0][j]+a.v[i][1]*(long long)b.v[1][j])%mdn;
	}
	return c;
}
vec operator*(const vec&a,const mat&b){
	vec c;
	for(int i=0;i<2;i++){
		c.v[i]=(a.v[0]*(long long)b.v[0][i]+a.v[1]*(long long)b.v[1][i])%mdn;
	}
	return c;
}

struct node{
	mat v;
	node *c[2];
}pool[maxn*2];int ps;

mat m0[maxn],mt;

node* bt(int l,int r){
	node *rt=pool+ps++;
	if(l==r){
		rt->v=m0[l];
	}else{
		int m=(l+r)>>1;
		rt->c[0]=bt(l,m);rt->c[1]=bt(m+1,r);
		rt->v=rt->c[0]->v*rt->c[1]->v;
	}
	return rt;
}

mat prod(node *rt,int cl,int cr,int l,int r){
	int cm=(cl+cr)>>1;
	if(l==cl&&r==cr)return rt->v;
	else if(r<=cm)return prod(rt->c[0],cl,cm,l,r);
	else if(l>cm)return prod(rt->c[1],cm+1,cr,l,r);
	else return prod(rt->c[0],cl,cm,l,cm)*prod(rt->c[1],cm+1,cr,cm+1,r);
}

node *rt;

mat e;
mat qpw(mat bse,long long ex){
	mat ret=e;
	for(;ex;ex>>=1,bse=bse*bse)if(ex&1)ret=ret*bse;
	return ret;
}
mat tprod(long long a,long long b){
	if(a==b)return e;
	a++;
	if(a/n==b/n)return prod(rt,0,n-1,a%n,b%n);
	else return prod(rt,0,n-1,a%n,n-1)*qpw(mt,b/n-a/n-1)*prod(rt,0,n-1,0,b%n);
}

struct oper{
	long long t;int v,g;
};
bool operator<(const oper&a,const oper&b){
	return a.t<b.t;
}

oper o[maxn*2];

int main(){
	scanf("%lld%d%d",&k,&mdn,&n);
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)e.v[i][j]=int(i==j)%mdn;
	if(k<=1){
		printf("%lld",k%mdn);
		return 0;
	}
	for(int i=0;i<n;i++)scanf("%d",s+i),s[i]%=mdn;
	for(int i=0;i<n;i++){
		m0[i].v[0][1]=1%mdn;m0[i].v[1][1]=0;m0[i].v[1][0]=s[(i+n*2-2)%n];m0[i].v[0][0]=s[(i+n-1)%n];
	}
	rt=bt(0,n-1);
	mt=prod(rt,0,n-1,0,n-1);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		long long t;int v;
		scanf("%lld%d",&t,&v);
		v%=mdn;
		o[i*2+1].t=t+2;o[i*2+1].v=v;o[i*2+1].g=0;
		o[i*2+2].t=t+1;o[i*2+2].v=v;o[i*2+2].g=1;
	}
	int tm=2*m+1;
	o[tm].t=k;o[tm].g=-1;
	sort(o+1,o+1+tm);
	long long rp=1;
	vec cur;cur.v[0]=1%mdn;cur.v[1]=0;
	for(int i=1;i<=tm;i++){
		mat cmat=m0[o[i].t%n];int crp=i;bool ed=0;
		for(int j=i;j<=tm&&o[j].t==o[i].t;j++){
			if(o[j].g==-1){
				ed=1;
			}else if(o[j].g==0)cmat.v[1][0]=o[j].v;
			else cmat.v[0][0]=o[j].v;
			crp=j;
		}
		if(o[i].t>rp){
			cur=cur*tprod(rp,o[i].t-1)*cmat;
			rp=o[i].t;
		}
		if(ed){
			printf("%d",cur.v[0]);
			return 0;
		}
		i=crp;
	}
	return 0;
}