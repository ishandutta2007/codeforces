#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e5+10,B=46;
int n,b[o],q,bl[o],L[o],R[o],ans,f[o/B+5][B+5];
void build(int id){
	for(int i=1,l,r,md,t;i<=R[id]-L[id]+1;f[id][i++]=l) for(l=f[id][i-1],r=n;l<r;){
		t=md=l+r>>1;
		for(int j=L[id];j<=R[id];++j) t+=(t>=b[j]);
		if(t-md>=i) r=md;else l=md+1;
	}
	for(int i=R[id]-L[id]+2;i<=B;++i) f[id][i]=n;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]),R[bl[i]=i/B+1]=i;
	for(int i=n;i;--i) L[bl[i]]=i;
	for(int i=1;i<=bl[n];++i) build(i);
	scanf("%d",&q);
	for(int opt,i;q--;){
		scanf("%d%d",&opt,&i);
		if(opt==1) scanf("%d",&b[i]),build(bl[i]);
		else{
			ans=b[i];
			for(int j=i+1;bl[j]==bl[i];++j) ans+=(ans>=b[j]);
			for(int j=bl[i]+1;j<=bl[n];++j) ans+=upper_bound(f[j]+1,f[j]+B+1,ans)-f[j]-1;
			printf("%d\n",n-ans);
		}
	}
	return 0;
}