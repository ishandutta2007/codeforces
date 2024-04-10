#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
const ll inf=0x3f3f3f3fll;
int n,m;
int vis[N];
int a[N];
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;ans++;
		for(j=i+1;j<=n;j++)
			if(a[j]%a[i]==0) vis[j]=1;
	}
	cout<<ans;
	return 0;
}