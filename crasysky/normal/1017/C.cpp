#include <iostream>
#include <cmath>
#include <cstdio>
#define maxn 1000006
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
	int m = sqrt(n);
	int len = n;
	for (int i = 1; i <= n / m; ++ i){
		for (int j = 1; j <= m; ++ j)
			cout << len - m + j << " ";
		len -= m;
	}
	for (int i = 1; i <= len; ++ i)
		cout << i << " ";
}