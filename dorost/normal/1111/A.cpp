#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool is_vow(char c){
	if (c == 'a' || c == 'u' || c == 'e' || c == 'o' || c == 'i')
		return true;
	else
		return false;
}

int main(){
	string s, t;
	cin >> s >> t;
	bool f = true;
	if (s.size() != t.size())
		f = false;
	for (int i = 0; i < s.size(); i++){
		if (is_vow(s[i]) != is_vow(t[i])){
			f = false;
		}
	}
	cout << (f ? "YES" : "NO");
}