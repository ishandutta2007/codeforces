#include <algorithm>
#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int a[1000006], b[1000006], _a[1000006], _b[1000006];
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
	for (int i = 1; i <= n; ++ i)
		_a[i] = read();
	for (int i = 2; i <= n; ++ i)
		a[i] = _a[i] - _a[i - 1];
	sort(a + 2, a + 1 + n);
	for (int i = 1; i <= n; ++ i)
		_b[i] = read();
	for (int i = 2; i <= n; ++ i)
		b[i] = _b[i] - _b[i - 1];
	sort(b + 2, b + 1 + n);
	if (_a[1] != _b[1]){
		cout << "No" << endl;
		return 0;
	}
	for (int i = 2; i <= n; ++ i)
		if (a[i] != b[i]){
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl;
}