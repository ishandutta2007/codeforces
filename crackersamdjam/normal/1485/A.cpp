#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){
	int t, a, b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		int ans = 1e9;
		for(int i = max(b, 2); i <= b+50; i++){
			int cnt = i-b;
			int aa = a, bb = i;
			while(aa){
				aa /= bb;
				cnt++;
			}
			ans = min(ans, cnt);
		}
		cout<<ans<<'\n';
	}
}