#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxm 1000005
#define db long double
#define E 1e-14
#define sqr(x) ((x)*(x)) 
using namespace std;

const db Pi=acos(-1);
int n,d,i,j,k,x,y,r,ans,tot,cnt; db dis;
struct arr{db x; int d;} a[maxm];
int cmp(arr a,arr b){return a.x<b.x||abs(a.x-b.x)<=E&&a.d>b.d;}

int check(int R){
	if (R+r<dis||abs(R-r)>dis) return 0;
	return 1;
}

void add(db l,db r){
	++tot,a[tot].x=l,a[tot].d=1;
	++tot,a[tot].x=r,a[tot].d=-1;
}

void Doit(db R){
	db p=abs(acos((sqr(dis)+sqr(R)-sqr(r))/(2*dis*R)));
	db q=atan2(y,x);
	db ll=q-p,rr=q+p;
	while (ll<0) ll+=2*Pi; while (ll>2*Pi) ll-=2*Pi;
	while (rr<0) rr+=2*Pi; while (rr>2*Pi) rr-=2*Pi;
	if (ll<=rr) add(ll,rr);
	else add(ll,2*Pi),add(0,rr);
}

int main(){
	scanf("%d%d",&n,&d);
	while (n--){
		scanf("%d%d%d",&x,&y,&r);
		dis=sqrt(sqr(x)+sqr(y));
		k=(dis-r)/d;
		if (k<=0) k=1; else 
		if (sqr(k*d+r)!=sqr(x)+sqr(y)) k++;
		for(;check(k*d);k++)
			Doit(k*d);
	}
	sort(a+1,a+1+tot,cmp);
	for(i=1;i<=tot;i++){
		cnt+=a[i].d;
		ans=max(ans,cnt);
	}
	printf("%d",ans);
}