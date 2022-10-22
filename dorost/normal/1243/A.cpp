//***in the name of GOD***//

#include<bits/stdc++.h>

using namespace std;

int main(){
	int q,n;
	cin >> q;
	while(q--){
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int as = 0;
		for(int i = 1; i <= n; i++){
			int ans = 0;
			for(int j = 0; j < n; j++){
				if(a[j] >= i){
					ans++;
				}
			}
			if(ans >= i){
				as = i;
			}
		}
		cout << as << endl;
	}
}