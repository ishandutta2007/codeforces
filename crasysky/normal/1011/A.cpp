#include <algorithm>
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
	int n = read(), k = read();
	char s[102];
	cin >> s;
	sort(s, s + n);
	int ans = 0, last = -1;
	for (int i = 0; i < n; ++ i)
		if ((s[i] - 'a' + 1) - last > 1){
			ans += s[i] - 'a' + 1;
			if (-- k == 0){
				cout << ans << endl;
				return 0;
			}
			last = s[i] - 'a' + 1;
		}
	cout << -1 << endl;
}