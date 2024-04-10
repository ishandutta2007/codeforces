#include <bits/stdc++.h>

using namespace std;

int Type[5000000], Val[5000000];
int n;

void mod(int &x) {
	if(x % 2 == 1) x += 1;
	else x -= 1;
}
void add(int &x, int v) {
	x -= v;
	while(x <= 0) x += n;
	while(x > n) x -= n;
}

void Read(int &x) {
	char c, sgn = 0;
	for(c = getchar(); !isdigit(c) && c != '-'; c = getchar());
	if(c == '-') sgn = 1, c = getchar();
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	if(sgn) x = -x;
}

int main() {
	int q;
	Read(n); Read(q);

	for(int i = 1; i <= q; ++i) {
		Read(Type[i]);
		if(Type[i] == 1) Read(Val[i]);
	}

	int p1 = 1, p2 = 2;
	for(int i = q; i >= 1; --i) {
		if(Type[i] == 2) {
			mod(p1);
			mod(p2);
		} else {
			add(p1, Val[i]);
			add(p2, Val[i]);
		}
	}

	for(int i = 1; i <= n / 2; i += 1) {
		cout << p1 << " " << p2 << " ";
		p1 += 2;
		p2 += 2;
		if(p1 > n) p1 -= n;
		if(p2 > n) p2 -= n;
	}

	return 0;
}