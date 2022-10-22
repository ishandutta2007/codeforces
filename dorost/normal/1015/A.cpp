#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
	int t,n,a,b;
	cin >> t >> n;
	bool s[n];
	for(int i = 0; i < n; i++){
		s[i] = true;
	}
	for(int i = 0; i < t; i++){
		cin >> a >> b;
		for(int i = a - 1; i < b; i++){
			s[i] = false;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i]){
			ans++;
		}
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++){
		if(s[i]){
			cout << i + 1 << ' '; 
		}
	}	
}