#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second 

int main(){
	string s;
	cin >> s;
	int n = s.size();
	bool f = true, h = true;
	int x = -1, y = -1, v = -1, w = -1;
	for (int i = 0 ; i < n; i++){
		if(s[i] == 'A' && s[i + 1] == 'B'){
			if(f)
				x = i;
			y = i;
			f = false;
		}
		if(s[i] == 'B' && s[i + 1] == 'A'){
			if(h)
				v = i;
			w = i;
			h = false;
		}
	}
	if(x == -1 || v == -1 || max(abs(w - x), abs(v - y)) < 2)
		cout << "NO\n";//<< x << ' ' << y << ' ' << v << ' ' << w;
	else
		cout << "YES\n";
}