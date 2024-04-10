#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define clr(x) memset(x,0,sizeof x)
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef double ld;

const ld eps=1e-6,Pi=acos(-1);
ld mo(ld x,ld y){return sqrt(x*x+y*y);}
ld fix(ld a){return a>Pi?a-2*Pi:(a<-Pi?a+2*Pi:a);}
int cmp(ld a,ld b){return fabs(a-b)<eps?0:a<b?-1:1;}

const int N=100005;
ld d[N],k[N],b[N],dir[N],L[N],R[N],X[N],ox,oy,l,r=1e10,ans;
int id[N],n,cnt,aim,acc;

void create(ld r){
	cnt=0;
	rep(i,1,n){
		if(d[i]>r)continue;
		ld de=acos(d[i]/r);
		L[i]=fix(dir[i]-de);
		R[i]=fix(dir[i]+de);
		if(L[i]>R[i])swap(L[i],R[i]);
		id[++cnt]=i;
	}
}

int a[N],c[N];
void upd(int x,int y){
	for(;x<N;x+=x&-x)c[x]+=y;
}
int qry(int x){
	int res=0;
	for(;x;x-=x&-x)res+=c[x];
	return res;
}
int calc(){
	int res=0,t=0; clr(c),clr(a);
	rep(i,1,cnt) X[++t]=L[id[i]],X[++t]=R[id[i]];
	sort(X+1,X+t+1);
	rep(i,1,cnt){
		int A=lower_bound(X+1,X+t+1,L[id[i]])-X;
		int B=lower_bound(X+1,X+t+1,R[id[i]])-X;
		a[A]=B;
	}
	rep(i,1,t)
		if(a[i]){
			res+=qry(a[i])-qry(i);
			if(res>aim)return aim+1;
			upd(a[i],1);
		}
	return res;
}

set<pair<ld,int> > s;
int push(int u,int v){
	ld x=(b[u]-b[v])/(k[v]-k[u]);
	ld d=mo(x-ox,k[u]*x+b[u]-oy);
	return d<r-eps?(ans+=d,acc++,1):0;
}
void solve(){
	sort(id+1,id+cnt+1,[&](int a,int b){
		return L[a]<L[b];
	});
	rep(i,1,cnt){
		auto it=s.lower_bound(mp(L[id[i]],0));
		for(;it!=s.end()&&it->fi<R[id[i]];it++)
			if(!push(id[i],it->se))break;
		s.insert(mp(R[id[i]],id[i]));
	}
}

int main(){
	scanf("%d",&n);
	scanf("%lf%lf%d",&ox,&oy,&aim);
	ox/=1000,oy/=1000;
	rep(i,1,n){
		scanf("%lf%lf",&k[i],&b[i]);
		k[i]/=1000,b[i]/=1000;
		ld A=k[i],B=-1,C=b[i];
		d[i]=fabs(A*ox+B*oy+C)/mo(A,B);
		dir[i]=atan(k[i])+(cmp(oy,k[i]*ox+b[i])<0?Pi/2:-Pi/2);
	}
	while(r-l>eps*l){
		ld mid=(l+r)*0.5;
		create(mid);
		if(calc()<aim)l=mid;
		else r=mid;
	}
	r=l,create(r),solve();
	ans+=(aim-acc)*r;
	printf("%.8lf\n",(double)ans);
	return 0;
}