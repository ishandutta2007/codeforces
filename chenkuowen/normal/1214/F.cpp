#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
typedef long long ll;
int a[N],b[N],n,m,halfm,poi[N]; ll d1[N],d2[N];
pair<int,int> a1[N],b1[N];
void opera(int l,int r,ll d[],ll k){ //[l,r)
	if(l==r) return;
	l=(l+n)%n;
	r=(r+n)%n;
//	printf("<%d %d %lld>",l,r,k);
	d[l]+=k;
	d[r]-=k;
	if(l>=r) d[0]+=k;
}
void solvea(int a[],int b[],ll d[]){
	int p1=n,p2=n,p3=n; halfm=m>>1;
	for(int i=n;i>=1;--i){
		while(p1>=1&&a[i]-b[p1]<-halfm) --p1;
		while(p2>=1&&a[i]-b[p2]<0) --p2;
		while(p3>=1&&a[i]-b[p3]<=halfm) --p3;
//		printf("|%d %d %d|",p1,p2,p3);
		opera(p1+1-i,n+1-i,d,a[i]+m);
		opera(p2+1-i,p1+1-i,d,-a[i]);
		opera(p3+1-i,p2+1-i,d,a[i]);
		opera(1-i,p3+1-i,d,-a[i]);
	}
	for(int i=1;i<n;++i) d[i]+=d[i-1];
//	for(int i=0;i<n;++i) printf("|%lld|",d[i]); puts("");
}
void solveb(int a[],int b[],ll d[]){
	int p1=1,p2=1,p3=1; int halfm=m>>1;
	for(int i=1;i<=n;++i){
		while(p1<=n&&a[p1]-b[i]<-halfm) ++p1;
		while(p2<=n&&a[p2]-b[i]<0) ++p2;
		while(p3<=n&&a[p3]-b[i]<=halfm) ++p3;
//		printf("|%d %d %d|",p1,p2,p3);
		opera(i-n,i-(p3-1),d,b[i]+m);
		opera(i-(p3-1),i-(p2-1),d,-b[i]);
		opera(i-(p2-1),i-(p1-1),d,b[i]);
		opera(i-(p1-1),i,d,-b[i]);
	}
	for(int i=1;i<n;++i) d[i]+=d[i-1];
//	for(int i=0;i<n;++i) printf("|%lld|",d[i]); puts("");
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a1[i].first),a1[i].second=i;
	for(int i=1;i<=n;++i)
		scanf("%d",&b1[i].first),b1[i].second=i;
	sort(a1+1,a1+n+1);
	sort(b1+1,b1+n+1);
	for(int i=1;i<=n;++i) a[i]=a1[i].first,b[i]=b1[i].first;
//	for(int i=1;i<=n;++i) printf("<%d>",a[i]); puts("");
//	for(int i=1;i<=n;++i) printf("<%d>",b[i]); puts("");
	solvea(a,b,d1);
	solveb(a,b,d2);
	ll ans=(ll)2e18; int k=0;
	for(int i=0;i<n;++i){
//		printf("/%lld/",d1[i]+d2[i]);
		if(d1[i]+d2[i]<ans) ans=d1[i]+d2[i],k=i;
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i) {
		poi[a1[i].second]=b1[(i+k-1)%n+1].second;
	}
	for(int i=1;i<=n;++i) printf("%d ",poi[i]); puts("");
	return 0;
}