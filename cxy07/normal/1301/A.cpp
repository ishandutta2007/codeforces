//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int T,n;
char a[MAXN],b[MAXN],c[MAXN];
bool flag = true;

int main () {
	cin >> T;
	while(T--) {
		cin >> a + 1 >> b + 1 >> c + 1;
		flag = true;
		n = strlen(a + 1);
		for(register int i = 1;i <= n; ++i)
			if(c[i] != a[i] && c[i] != b[i]) {flag = false; break;}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}