#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k,a[100005],b[100005],c[100005],mx[100005];
int main(){
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++)cin>>b[i],mx[b[i]]=max(mx[b[i]],a[i]);
	int ans=0;
	for (int i=1;i<=k;i++){
		cin>>c[i];
		if (a[c[i]]!=mx[b[c[i]]])ans++;
	}
	cout<<ans<<endl;
	return 0;
}