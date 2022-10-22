#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const int inf=0x3f3f3f3f;
const int mod=998244353;
int n;
int a[N];
int mn[N],mx[N];
int main()
{
	cin>>n;
	int i,j;
	memset(mn,0x3f,sizeof(mn));
	for(i=1;i<=n;i++){
		cin>>a[i];
		mn[a[i]]=min(mn[a[i]],i);
		mx[a[i]]=max(mx[a[i]],i);
	}
	if(a[1]!=a[n]){
		cout<<n-1;
		return 0;
	}
	int ans=0;
	for(i=1;i<=n;i++){
		if(i==a[1]) continue;
		ans=max(ans,mx[i]-1);
	}
	for(i=1;i<=n;i++){
		if(i==a[n]) continue;
		ans=max(ans,n-mn[i]);
	}
	cout<<ans;
	return 0;
}