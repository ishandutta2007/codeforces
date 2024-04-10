#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
int t,n,m,a[105][105],ans;
inline int calc(int a,int b,int c,int d,int e){
	return abs(a-e)+abs(b-e)+abs(c-e)+abs(d-e)+abs(e-e); 
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)scanf("%lld",&a[i][j]);
		ans=0;
		for (int i=1;i<=n/2;i++) 
			for (int j=1;j<=m/2;j++){
				int k=n-i+1,l=m-j+1;
				if (i==k||j==l)continue;
				int v1=a[i][j],v2=a[i][l],v3=a[k][j],v4=a[k][l];
				ans+=min(min(calc(v1,v2,v3,v4,v1),calc(v1,v2,v3,v4,v2)),min(calc(v1,v2,v3,v4,v3),calc(v1,v2,v3,v4,v4)));
			}
		if (n%2==1){
			for (int i=1;i<=m/2;i++)
				ans+=abs(a[(n+1)/2][i]-a[(n+1)/2][m-i+1]);
		}
		if (m%2==1){
			for (int i=1;i<=n/2;i++)
				ans+=abs(a[i][(m+1)/2]-a[n-i+1][(m+1)/2]);
		}
		cout<<ans<<endl;
	}
	return 0;
}