#include <iostream>
#include <cstdio>
#include <map>
#define fi first
#define se second
using namespace std;
const int maxn = 1000006;
long long v[maxn];
int b[maxn], cnt[102];
string s;
long long read(){
	long long c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int n = read();
	for (int i = 1; i <= n; ++ i){
		long long a = read();
		v[i] = a;
		int c = 0;
		while ((a & 1) == 0)
			++ c, a >>= 1;
		b[i] = c;
		++ cnt[c];
	}
	int mx = 0;
	for (int i = 1; i <= 100; ++ i)
		if (cnt[i] >= cnt[mx])
			mx = i;
	cout << n - cnt[mx] << endl;
	for (int i = 1; i <= n; ++ i)
		if (b[i] != mx)
			cout << v[i] << " ";
	cout << endl;
}