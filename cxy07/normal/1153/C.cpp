//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;

int n,l,r;
char c[MAXN];
int main () {
	cin >> n;
	cin >> c;
	if(c[0] == '?') c[0] = '(';
	if(c[n - 1] == '?') c[n - 1] = ')';
	if(c[0] != '(' || c[n - 1] != ')') return puts(":("),0;
	if(n & 1) return puts(":("),0;
	if(n == 2) return cout << c << endl,0;
	for(int i = 1;i < n - 1; ++i) {
		if(c[i] == '(') l++;
		if(c[i] == ')') r++;
	}
	if(l + 1 > n / 2 || r + 1 > n / 2) return puts(":("),0;
	for(int i = 1;i < n - 1; ++i) {
		if(c[i] == '?') {
			if(l + 1 < n / 2) l++,c[i] = '(';
			else r++,c[i] = ')';
		}
	}
	int chk = 0;
	for(int i = 0;i < n - 1; ++i) {
		if(c[i] == '(') chk++;
		if(c[i] == ')') {
			chk--;
			if(chk <= 0) return puts(":("),0;
		}
	}
	cout << c << endl;
	return 0;
}