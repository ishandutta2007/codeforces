#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int T = read();
	while (T --){
		int x = read(), y = read(), z = read();
		cout << max(0, z - max(0, (int)(floor((y + z - x) / 2.0) + 1)) + 1) << endl;
	}
}