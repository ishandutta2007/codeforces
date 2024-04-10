//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 110;
const int INF = 2e9;
const int mod = 1e9 + 7;

int T,n;
char s[MAXN];
bool flag;

signed main () {
	cin >> T;
	while(T--) {
		cin >> s + 1;
		flag = true;
		n = strlen(s + 1);
		for(register int i = 2;i <= n; ++i)
			if(s[i] != s[i - 1]) {flag = false; break;}
		if(flag) {
			for(register int i = 1;i <= n; ++i)
				cout << s[i];
			cout << endl;
			continue;
		}
		for(register int i = 1;i <= n; ++i)
			cout << "01";
		cout << endl;
	}
	return 0;
}