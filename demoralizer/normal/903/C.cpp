#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	map<int, int> m;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		m[x]++;
	}
	
	int rem = 0;
	for(auto x:m){
		int c = x.second;
		rem -= min(rem, c);
		rem += c;
	}
	
	cout << rem;
	
}