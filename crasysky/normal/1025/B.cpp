#include <iostream>
#include <cstdio>
using namespace std;
int a[2][1000006];
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
int n;
bool check(int x){
	for (int i = 2; i <= n; ++ i)
		if (a[0][i] % x && a[1][i] % x)
			return false;
	return true;
}
int main(){
	n = read();
	for (int i = 1; i <= n; ++ i)
		a[0][i] = read(), a[1][i] = read();
	for (int i = 2; i <= 100000; ++ i)
		if (a[0][1] % i == 0 || a[1][1] % i == 0){
			while (a[0][1] % i == 0)
				a[0][1] /= i;
			while (a[1][1] % i == 0)
				a[1][1] /= i;
			if (check(i)){
				cout << i << endl;
				return 0;
			}
		}
	if (a[0][1] != 1 && check(a[0][1])){
		cout << a[0][1] << endl;
		return 0;;
	}
	if (a[1][1] != 1 && check(a[1][1])){
		cout << a[1][1] << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}