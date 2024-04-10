#include <bits/stdc++.h>
using namespace std;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	string t = "";
	for(char c : s) {
		if(c == '/') {
			if(t.size() == 0 || t.back() != '/')
				t += '/';
		} else
			t += c;
	}
	if(t.size() > 1 && t.back() == '/')
		t.pop_back();
	cout << t << '\n';
}