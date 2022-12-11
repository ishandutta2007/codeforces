#include<bits/stdc++.h>
using namespace std;
const int N=5050;
int T,n,m,k,a[N],b[N],p,q[N],l,r,ans;
void solve(){
	scanf("%d%d%d",&n,&m,&k);p=max(m-k,1);ans=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)b[i]=max(a[i],a[i+n-m]);
	l=1;r=0;
	for(int i=1;i<p;q[++r]=i++)while(l<=r&&b[q[r]]>=b[i])r--;
	for(int i=p;i<=m;i++){
		while(l<=r&&q[l]<i-p+1)l++;
		while(l<=r&&b[q[r]]>=b[i])r--;
		q[++r]=i;ans=max(ans,b[q[l]]);
	}
	cout<<ans<<endl;
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	
	return 0;
}