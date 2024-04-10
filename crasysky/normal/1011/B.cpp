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

int m, n, a[102];
bool check(int x){
	int cnt = 0;
	for (int i = 1; i <= 100; ++ i)
		cnt += a[i] / x;
	if (cnt >= m)
		return true;
	return false;
}
int bs(int l, int r){
	int ans = 0;
	while (l <= r){
		int m = l + r >> 1;
		if (check(m)){
			ans = m;
			l = m + 1;
		}
		else
			r = m - 1;
	}
	return ans;
}
int main(){
	m = read(), n = read();
	for (int i = 1; i <= n; ++ i){
		int x = read();
		a[x] ++;
	}
	cout << bs(1, 1000000000) << endl;
}