#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#define mp make_pair
#define fi first
#define se second
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
		int n = read(), x = read(), mx0 = 0, mx1 = 0;
		for (int i = 1; i <= n; ++ i){
			int p = read(), q = read();
			mx0 = max(mx0, p - q);
			mx1 = max(mx1, p);
		}
		if (mx0 == 0 && mx1 < x)
			cout << -1 << endl;
		else{
			if (mx0 && mx1 < x)
				cout << (x - mx1 + mx0 - 1) / mx0 + 1 << endl;
			else
				cout << 1 << endl;
		}
	}
}