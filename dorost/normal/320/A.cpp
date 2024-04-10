#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	string s;
	cin >> s;
	bool f = true;
	for (int i = 0; i < s.size() && f; i++){
		if(s[i] == '1' && s[i + 1] == '4' && s[i + 2] == '4')
			i += 2;
		else if(s[i] == '1' && s[i + 1] == '4')
			i++;
		else if(s[i] == '1')
			i += 0;
		else 
			f = false;
	}
	cout << (f ? "YES" : "NO");
}