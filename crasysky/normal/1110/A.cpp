#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
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
	int b = read(), k = read(), ans = 0;
	for (int i = 1; i <= k; ++ i){
		int a = read();
		if (a % 2 == 1 && (i == k || b % 2 == 1))
			ans ^= 1;
	}
	if (ans == 1)
		cout << "odd" << endl;
	else
		cout << "even" << endl;
}