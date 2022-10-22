#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	string s;
	cin >> s;
	s = 'A' + s + 'A';
	int x = -1, maxi = 0;
	for (int i = 0; i < s.size(); i++){
		if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'Y' || s[i] == 'O' || s[i] == 'U'){
			maxi = max(maxi, i - x);
			x  = i;
		}
	}
	cout << max(maxi, (int)s.size() - x);

}