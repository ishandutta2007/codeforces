#include <iostream>
#include <cstdio>
#define maxn 1000006
using namespace std;
string a, b;
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
	cin >> a >> b;
	int cnt0 = 0, cnt1 = 0, _cnt0 = 0, _cnt1 = 0;
	for (int i = 0; i < n; ++ i)
		if (a[i] == '0'){
			if (b[i] == '0')
				++ cnt0;
			else
				++ _cnt0;
		}
		else{
			if (b[i] == '0')
				++ cnt1;
			else
				++ _cnt1;
		}
	cout << 1LL * cnt0 * (cnt1 + _cnt1) + 1LL * _cnt0 * cnt1 << endl;
}