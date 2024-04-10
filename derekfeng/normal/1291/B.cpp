#include <bits/stdc++.h>
using namespace std;
int t,n,a[300004];
bool can[300004],d[300004];
int main(){
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		can[0]=d[n+1]=1;
		for (int i=1;i<=n;i++){
			can[i]=can[i-1];
			if (a[i]<i-1) can[i]=0;
		}
		for (int i=n;i>=1;i--){
			d[i]=d[i+1];
			if (a[i]<n-i) d[i]=0;
		}
		bool ok=0;
		for (int i=1;i<=n;i++)
			if (can[i]&&d[i]) ok=1;
		if (ok) puts("YES");
		else puts("NO");
	}
}