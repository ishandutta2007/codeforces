#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int t, n, k, a[105];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		for(int i = 0; i < n-1; i++){
			int sub = min(k, a[i]);
			k -= sub;
			a[i] -= sub;
			a[n-1] += sub;
		}
		for(int i = 0; i < n; i++)
			cout<<a[i]<<' ';
		cout<<'\n';
	}
}