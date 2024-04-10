#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
int a[N];
int pre[N],suf[N],pmx[N],smx[N];
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	a[0]=a[n+1]=n+1;
	for(i=1;i<=n;i++){
		if(a[i]>a[i-1]) pre[i]=pre[i-1]+1;
		else pre[i]=1;
	}
	for(i=n;i;i--){
		if(a[i]>a[i+1]) suf[i]=suf[i+1]+1;
		else suf[i]=1;
	}
	for(i=1;i<=n;i++) pmx[i]=max(pmx[i-1],max(pre[i],suf[i]));
	for(i=n;i;i--) smx[i]=max(smx[i+1],max(pre[i],suf[i]));
	int ans=0;
	for(i=1;i<=n;i++){
		if(a[i]>a[i-1]&&a[i]>a[i+1]&&pre[i]==suf[i]){
			if(!(pre[i]&1)) continue;
			if(pmx[i-pre[i]+1]>=pre[i]||smx[i+suf[i]-1]>=suf[i]) continue;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}