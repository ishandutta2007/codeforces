#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	string s;
	cin >> s;
	bool f = false;
	for (int i = 1; i < s.size(); i++)
		if(s[i] == '1')
			f = true;
	cout << (s.size() + f) / 2;
}