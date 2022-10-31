#include <iostream>
#include <cstdio>
using namespace std;
int a[2][2];
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch&& ch <= '9'){
		cnt = cnt * 10 + ch- '0';
		ch = getchar();
	}
	return cnt;
}
int n, arr[1000006];
string s;
int main(){
	cin >> s;
	int n = s.length();
	for (int i = 1; i <= n; ++ i)
		arr[i] = s[i - 1] == 'b' ? 1 : 0;
	int cnt0 = 1;
	for (int i = 2; i <= n; ++ i)
		if (arr[i] != arr[i - 1])
			++ cnt0;
		else
			break;
	int cnt1 = 1;
	for (int i = n - 1; i; -- i)
		if (arr[i] != arr[i + 1])
			++ cnt1;
		else
			break;
	int ans = 1, cnt = 1;
	for (int i = 2; i <= n; ++ i)
		if (arr[i] != arr[i - 1]){
			++ cnt;
			ans = max(ans, cnt);
		}
		else
			cnt = 1;
	cout << max(arr[1] != arr[n] ? min(cnt0 + cnt1, n) : 0, ans) << endl;
	return 0;
}