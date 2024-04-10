#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;	cin >> s;
	
	char cur = 'a';
	for (char c:s){
		if (c == cur){
			cur++;
			continue;
		}
		if (c < cur) continue;
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	return 0;
}