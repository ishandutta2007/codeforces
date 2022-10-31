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
	int w1 = read(), h1 = read(), w2 = read(), h2 = read();
	cout << h1 * 2 + w1 + (w1 - w2) + 2 * h2 + w2 + 4 << endl;
}