	#include<bits/stdc++.h>
	using namespace std;
	
	int main() {
		int t;
		cin >> t;
		while(t--) {
			int n;
			cin >> n;
			cout << n << endl;
			vector<int>a(n+1);
			for(int i=1;i<=n;++i) a[i] = i;
			int x = n;
			for(int c=1;c<=n;++c) cout << c << " ";
			cout << endl; 
			for(int l=0;l<n-1;++l) {
				int s = a[x];
				a[x] = a[x-1];
				a[x-1] = s;
				x--;
				// 1 3 2, n=3
				for(int o=1;o<=n;++o) {
					cout << a[o] << " ";
				}
				cout << endl;
			}
		}
	}