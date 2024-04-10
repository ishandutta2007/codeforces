#include <iostream>
#include <cstdio>
#define maxn 1000006
using namespace std;
int a[maxn];
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
	for (int i = 1; i <= n; ++ i){
		int w = read(), x = read(), y = read(), z = read();
		a[i] = w + x + y + z;
	}
	int ans = 0;
	for (int i = 2; i <= n; ++ i)
		if (a[i] > a[1])
			++ ans;
	cout << ans + 1 << endl;
}