#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int a = 0; int b = 0;
		for(int i = 0; i<m; i++){
			int x,y;
			cin >> x >> y;
			a = max(a,x);
			b = max(b,y);
		}
		if(a+b<=n){
			b = n-a;
			for(int i = 0; i<a; i++){
				cout << "R";
			}
			for(int i = 0; i<b; i++){
				cout << "W";
			}
			cout << "\n";
		}
		else{
			cout << "IMPOSSIBLE\n";
		}
	}
	return 0;
}