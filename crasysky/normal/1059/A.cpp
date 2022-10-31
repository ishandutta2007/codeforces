#include <iostream>
#include <cstdio>
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
	int n = read(), l = read(), a = read();
	int last = 0, ans = 0;
	for (int i = 1; i <= n; ++ i){
		int t = read(), l = read();
		ans += (t - last) / a;
		last = t + l;
	}
	ans += (l - last) / a;
	cout << ans << endl;
}