#include <algorithm>
#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 1000006;
const int P = 1e9 + 7;
int n;
pair <int, int> b[maxn];
int C[4][maxn];
int add(int x, int y){
	return x + y >= P ? x + y - P : x + y;
}
void upd(int& x, int y){
	x = x + y >= P ? x + y - P : x + y;
}
void add1(int w, int x, int y){
	for (int i = x; i <= n; i += i & -i) upd(C[w][i], y);
}
int sum1(int w, int x){
	int ans = 0;
	for (int i = x; i; i -= i & -i) upd(ans, C[w][i]);
	return ans;
}
void add2(int w, int x, int y){
	for (int i = x; i; i -= i & -i) upd(C[w][i], y);
}
int sum2(int w, int x){
	int ans = 0;
	for (int i = x; i <= n; i += i & -i) upd(ans, C[w][i]);
	return ans;
}
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	n = read();
	for (int i = 1; i <= n; ++ i){
		int x = read();
		b[i] = mp(x, i);
	}
	sort(b + 1, b + 1 + n);
	int s = 0, ans = 0;
	for (int t = 1; t <= n; ++ t){
		int i = b[t].se;
		upd(s, 1LL * i * (n - i + 1) % P);
		
		int c = s;
		upd(c, P - add(1LL * i * sum1(0, i) % P, P - sum1(1, i)));
		upd(c, P - add(sum2(2, i), P - 1LL * sum2(3, i) * i % P));
		upd(ans, 1LL * c * b[t].fi % P);
		
		add1(0, i, i), add1(1, i, 1LL * i * i % P);
		add2(2, i, 1LL * i * (n - i + 1) % P), add2(3, i, n - i + 1);
	}
	cout << ans << endl;
}