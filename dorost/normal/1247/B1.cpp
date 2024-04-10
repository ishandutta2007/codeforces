#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
	int t,n,k,d;
	cin >> t;
	while(t--){
		cin >> n >> k >> d;
		int a[n] , b[n];
		int ans[n - d + 1] = {};
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = d - 1; i < n; i++){
			ans[i - d + 1] = d;
			for(int o = 0; o < n; o++){
				b[o] = a[o];
			}
			for(int g = i - d + 1; g < i + 1; g++){
				for(int j = i - d + 1; j < g; j++){
					if(b[g] == b[j]){
						ans[i - d + 1]--;
						b[j] = 200;						
					}
				}
			}
		}
		sort(ans,ans + n - d + 1);
		cout << ans[0] << ' ';
	}	
}