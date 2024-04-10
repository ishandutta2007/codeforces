//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int T;
int n,x,calc,now,ans;
char s[MAXN];

int main () {
	cin >> T;
	while(T--) {
		cin >> n >> x;
		cin >> s + 1;
		calc = now = ans = 0;
		for(register int i = 1;i <= n; ++i)
			calc += (s[i] == '0' ? 1 : -1);
		for(register int i = 0;i < n; ++i) {
			if(i) now += (s[i] == '0' ? 1 : -1);
			if(now == x && !calc) {ans = -1; break;}
			if(!calc) continue;
			if((x - now) % calc == 0 && (x - now) / calc >= 0) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}