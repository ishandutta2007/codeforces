//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 65010;

int n,ans = 0;
char c[MAXN];

int main () {
	scanf("%d\n",&n);
	cin >> c;
	for(int i = 1;i <= n; ++i) {
		if(((c[i - 1] - '0') & 1) == 0) 
			ans += i;
	}
	cout << ans << endl;
	return 0;
}