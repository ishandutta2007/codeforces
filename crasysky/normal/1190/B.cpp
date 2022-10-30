#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 2000006;
const int INF = 1e9;
long long a[maxn];
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int n = read();
	for (int i = 1; i <= n; ++ i)
		a[i] = read();
	if (n == 1){
		if (a[1] % 2 == 0)
			cout << "cslnb" << endl;
		else
			cout << "sjfnb" << endl;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	int c = 0;
	for (int i = 2; i <= n; ++ i)
		if (a[i] == a[i - 1]){
			++ c, -- a[i - 1];
			if (a[i] == 0)
				c += 100;
			break;
		}
	for (int i = 2; i <= n; ++ i)
		if (a[i] == a[i - 1])
			++ c;
	if (c > 1){
		cout << "cslnb" << endl;
		return 0;
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++ i)
		ans += a[i] - (i - 1);
	if ((ans & 1) ^ c)
		cout << "sjfnb" << endl;
	else
		cout << "cslnb" << endl;
	return 0;
}