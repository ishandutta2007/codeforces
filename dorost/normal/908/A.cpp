#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int ans = 0;
	string s;
	cin >> s;
	char c[10] = {'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7','9'};
	for(int i = 0; i < s.size(); i++){
		for(int j = 0 ; j < 10; j++){
			ans += (s[i] == c[j]);
		}
	}
	cout << ans;
}