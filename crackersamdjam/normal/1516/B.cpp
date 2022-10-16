#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int t, n, a[2005], psa[2005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n;
		int ok = 0;
		for(int i = 1; i <= n; i++){
			cin>>a[i];
			psa[i] = a[i]^psa[i-1];
		}
		for(int i = 1; i < n; i++){
			if(psa[i] == (psa[n]^psa[i])){
				ok = 1;
			}
		}
		for(int i = 1; i < n; i++){
			for(int j = i+1; j < n; j++){
				if(psa[i] == (psa[j]^psa[i]) and psa[i] == (psa[n]^psa[j])){
					ok = 1;
				}
			}
		}

		cout<<(ok ? "YES" : "NO")<<'\n';
	}
}