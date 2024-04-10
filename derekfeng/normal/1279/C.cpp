#include <bits/stdc++.h> 
using namespace std;
int n,a[100004],m,b[100004],d[100004];
long long ans;
bool ok[100004];
int main(){
	int T;cin>>T;
	while (T--){
		ans=0;
		int lst=0,maxn=0;
		cin>>n>>m;
		for (int i=1;i<=n;i++) ok[i]=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),d[a[i]]=i;
		for (int i=1;i<=m;i++){
			scanf("%d",&b[i]);
			if (d[b[i]]>maxn)ans+=2*(d[b[i]]-(i-1))-1;
			else ans++;
			maxn=max(maxn,d[b[i]]);
		}
		cout<<ans<<"\n";
	}
}