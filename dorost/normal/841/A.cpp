#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	map <char, int> mp;
	for (int i = 0; i < n; i++){
		mp[s[i]]++;
	}
	for (int i = 0; i < 26; i++){
		if(mp[i + 'a'] > k){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}