#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	int n = read();
	int lastx = -1, lasty = 0, ans = 0;
	for (int i = 1; i <= n; ++ i){
		int x = read(), y = read();
		int t = min(x, y) - max(lastx, lasty);
		if (t >= 0){
			ans += t;
			if (lastx != lasty)
				++ ans;
		}
		lastx = x, lasty = y;
	}
	cout << ans << endl;
}