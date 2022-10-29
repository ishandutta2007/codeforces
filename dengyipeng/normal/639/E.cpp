#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 150005
#define db double 
#define E 0.00000001
#define ll long long 
using namespace std;

int n,i,j,k,cnt,id[maxn];
struct arr{ll p,t;int i;} a[maxn];
db l,r,mid,ans,T;
int cmp(arr a,arr b){return a.p*b.t>b.p*a.t||a.p*b.t==b.p*a.t&&a.p<b.p;}
int cmp2(int i,int j){return a[i].p<a[j].p;}

struct Treearray{
	db s[maxn];
	void add(int x,db d){for(;x<=cnt;x+=x&-x) s[x]=max(s[x],d);}
	db sum(int x,db S=0){for(;x;x-=x&-x) S=max(S,s[x]);return S;}
} t;

//db val[maxn],val1[maxn];

int check(db c){
	ll s=0,s0;
	memset(t.s,0,sizeof(t.s));
	for(i=1;i<=n;i=j){
		s0=0;
		for(j=i;j<=n&&a[i].p*a[j].t==a[j].p*a[i].t;j++) s0+=a[j].t;
		for(k=i;k<j;k++) if (t.sum(a[k].i-1)>a[k].p*(1.0-c*(s+s0)/T)) return 0;
		for(k=i+1;k<j;k++) if (a[k-1].p<a[k].p){
			if (a[k-1].p*(1.0-c*(s+a[k-1].t)/T)>a[k].p*(1.0-c*(s+s0)/T))
				return 0;
		}
		for(k=i;k<j;k++) {
			t.add(a[k].i,a[k].p*(1.0-c*(s+a[k].t)/T));
//			val[k]=a[k].p*(1.0-c*(s+a[k].t)/T);
//			val1[k]=a[k].p*(1.0-c*(s+s0)/T);
		}
		s+=s0;
	}
	memset(t.s,0,sizeof(t.s));
	for(i=n;i>=1;i=j){
		s0=0;
		for(j=i;j>=1&&a[i].p*a[j].t==a[j].p*a[i].t;j--) s0+=a[j].t;
		for(k=i;k>j;k--) if (t.sum(a[k].i-1)>a[k].p*(1.0-c*s/T)) 
			return 0;
		for(k=i;k>j;k--) t.add(a[k].i,a[k].p*(1.0-c*(s-s0+a[k].t)/T));
		s-=s0;
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i].p);
	for(i=1;i<=n;i++) scanf("%lld",&a[i].t),T+=a[i].t;
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++) id[i]=i; sort(id+1,id+1+n,cmp2);
	for(i=1;i<=n;i++) {
		if (i==1||a[id[i]].p!=a[id[i-1]].p) cnt++;
		a[id[i]].i=cnt;
	}
	l=0,r=1,ans=0;
	while (l+E<=r){
		mid=(l+r)/2;
		if (check(mid)) ans=mid,l=mid;
		else r=mid;
	}
	printf("%.12lf",ans);
}