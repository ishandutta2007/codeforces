#include <bits/stdc++.h>
using namespace std;
int a[50005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i=1; i<=n; i++) cin >> a[i];
		int x, ans=n; cin >> x;
		for(int i=1; i<=n; i++) a[i]-=x;
		for(int i=2; i<=n; i++){
			if(a[i]+a[i-1]<0||a[i]+a[i-1]+a[i-2]<0) ans--, a[i]=1e9;
		}
		cout << ans << endl;
	}
	return 0;
}