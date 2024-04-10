//Code By CXY
#include<bits/stdc++.h>
using namespace std;

int T;
int a,b,c,ans = 0;

int main () {
	cin >> T;
	while(T--) {
		cin >> a >> b >> c;
		ans = 0;
		if(a) a--,ans++;
		if(b) b--,ans++;
		if(c) c--,ans++;
		if(a < b) swap(a,b);
		if(a < c) swap(a,c);
		if(a && b) a--,b--,ans++;
		if(a && c) a--,c--,ans++;
		if(b && c) b--,c--,ans++;
		if(a && b && c) a--,b--,c--,ans++;
		cout << ans << endl;
	}
	return 0;
}