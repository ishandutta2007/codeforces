#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[5004],b[5004];
ll pre[5004],suf[5004],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),pre[i]=pre[i-1]+(ll)a[i]*b[i];
	for(int i=n;i;i--)suf[i]=suf[i+1]+(ll)a[i]*b[i];
	ans=suf[1];
	for(int i=1;i<=n;i++){
		ll now=(ll)a[i]*b[i];
		for(int l=i-1,r=i+1;l>0&&r<=n;l--,r++){
			now+=(ll)a[l]*b[r]+(ll)a[r]*b[l];
			ans=max(ans,now+pre[l-1]+suf[r+1]);
		}
		now=0;
		for(int l=i,r=i+1;l>0&&r<=n;l--,r++){
			now+=(ll)a[l]*b[r]+(ll)a[r]*b[l];
			ans=max(ans,now+pre[l-1]+suf[r+1]);
		}
	}
	printf("%lld",ans);
}