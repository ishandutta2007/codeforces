#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;ll x,a[100004];
int main(){
	cin>>T;
	while (T--){
		int ans=0;
		cin>>n>>x;
		for (int i=0;i<n;i++) cin>>a[i];
		sort (a,a+n);
		ll d=0;
		for (int i=n-1,j=1;i>=0;i--,j++){
			d+=a[i];
			if (x*j<=d) ans=max(ans,j);
		}
		printf("%d\n",ans);
	}
}