#include <algorithm>
#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int a[1000006], b[1000006];
int gcd(int x, int y){
	if (y == 0)
		return x;
	return gcd(y, x % y);
}
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
	int q = read();
	while (q --){
		int a = read();
		if (a + 1 - ((a + 1) & -(a + 1))){
			for (int i = 0; i <= 25; ++ i)
				if (a < (1 << i)){
					cout << (1 << i) - 1 << endl;
					break;
				}
		}
		else{
			bool flag = false;
			for (int i = 2; i * i <= a; ++ i)
				if (a % i == 0){
					cout << a / i << endl;
					flag = true;
					break;
				}
			if (! flag)
				cout << 1 << endl;
		}
	}
}