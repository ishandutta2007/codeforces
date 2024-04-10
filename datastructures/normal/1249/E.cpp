#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,a[200005],b[200005],c,f[200005][2];
signed main(){
	cin>>n>>c;
	for (int i=1;i<n;i++)cin>>a[i];
	for (int i=1;i<n;i++)cin>>b[i];
	f[1][0]=0;f[1][1]=2e18;cout<<0<<' ';
	for (int i=2;i<=n;i++){
		f[i][0]=min(f[i-1][0],f[i-1][1])+a[i-1];
		f[i][1]=min(f[i-1][1]+b[i-1],f[i-1][0]+c+b[i-1]);
		cout<<min(f[i][0],f[i][1])<<' ';
	}
	cout<<endl;
}