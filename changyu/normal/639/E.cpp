#include<bits/stdc++.h>
typedef long long ll;
typedef double lf;
const int N=150003,EPS=1e-10,D=30;
struct participant{int p,t;}a[N];
int n,t[N];ll b[N],c[N],d[N];
bool Cmp(const participant&a,const participant&b){return(ll)a.p*b.t>(ll)b.p*a.t;}
bool Cmpt(const int&i,const int&j){return a[i].p<a[j].p;}
inline bool Check(lf g){
	lf x=0;
	std::sort(t+1,t+1+n,Cmpt);
	for(int i,j=1,k,l=1;j<=n;j++)if(j==n||a[t[j]].p!=a[t[j+1]].p){
	  for(k=l;k<=j;k++){
		i=t[k];
		if(x-EPS>a[i].p*(1-g/b[n]*d[i]))return 0;
	  }
	  for(k=l;k<=j;k++){
		i=t[k];
		x=std::max(x,a[i].p*(1-g/b[n]*c[i]));
	  }
	  l=j+1;
	}return 1;
}
int main(){
	lf l=0,r=1,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].p);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].t);
	std::sort(a+1,a+1+n,Cmp);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i].t;
	for(int i=1,j=0,k;i<=n;i++)if(i==n||(ll)a[i].p*a[i+1].t!=(ll)a[i+1].p*a[i].t){
	  for(k=j+1;k<=i;k++)c[k]=b[j]+a[k].t,d[k]=b[i];
	  j=i;
	}
	for(int i=1;i<=n;i++)t[i]=i;
	for(int j=0;j<D;j++)m=(l+r)/2,Check(m)?l=m:r=m;
	printf("%.12lf\n",m);
	return 0;
}