#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1e5;
int n,k;
int a[maxn+5],d[maxn+5];
ll sa[maxn+5],mna[maxn+5],mnd[maxn+5];
ll lf[maxn+5];
ll ans;
void make_lf(){
	ll sd=a[n];
	lf[n]=max(0,a[n]-d[n]);
	for(int i=n-1;i;i--){
		sd+=a[i];
		lf[i]=max(lf[i+1],sd-d[i]);
	}
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sa[i]=sa[i-1]+a[i];
	}
	mnd[0]=1<<30;
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		mnd[i]=min(mnd[i-1],(ll)d[i]);
	}
	make_lf();
	if(k==0){
		printf("%lld\n",lf[1]);
		return 0;
	}
	if(k>=2){
		ans=max(ans,sa[n]-mnd[n-1]);
		ans=max(ans,1ll*a[n]-d[n]);
	}
	ans=max(ans,lf[2]);
	for(int i=1;i<n;i++)
		ans=max(ans,sa[i]-mnd[i]+lf[i+1]);
	mna[n-1]=a[n-1];
	for(int i=n-2;i;i--) mna[i]=min(mna[i+1],(ll)a[i]);
	for(int i=1;i<n-1;i++) ans=max(ans,sa[n]-sa[i-1]-mna[i+1]-d[i]);
	printf("%lld\n",ans);
	return 0;
}