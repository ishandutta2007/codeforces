#include <iostream>
#include <cstdio>
using namespace std;
int n,a[500005],cnt[500005],fir[500005],lst[500005],f[500005];
int awa[500005],ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
		if (fir[a[i]]==0)fir[a[i]]=i;
		lst[a[i]]=i;
	}
	for (int i=1;i<=n;i++){
		f[i]=f[i-1];
		if (i==lst[a[i]])f[i]=max(f[i],f[fir[a[i]]-1]+cnt[a[i]]);
	}
	ans=f[n];
	for (int i=n;i>=1;i--){
		awa[a[i]]++;
		ans=max(ans,f[i-1]+awa[a[i]]);
	}
	cout<<n-ans<<endl;
	return 0;
}