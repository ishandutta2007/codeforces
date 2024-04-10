#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[100004];
int main(){
	cin>>T;
	while (T--){
		cin>>n;
		ll now=0;
		bool ok=0;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<n;i++){
			now+=a[i];
			if (now<=0) ok=1;
		}
		now=0;
		for (int i=n;i>1;i--){
			now+=a[i];
			if (now<=0) ok=1;
		}
		if (ok) puts("NO");
		else puts("YES");
	}
}