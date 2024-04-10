#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#define Pr pair <int, int>
#define Mp make_pair 
#define fi first
#define se second
using namespace std;
map <int, int> mp;
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int n = read(), P = read(), k = read();
	for (int i = 1; i <= n; ++ i){
		int a = read();
		int x = (P + 1LL * a * a % P * a % P * a % P - 1LL * k * a % P) % P;
		++ mp[x];
	}
	long long ans = 0;
	for (map <int, int> :: iterator it = mp.begin(); it != mp.end(); ++ it){
		int x = (*it).se;
		ans += x * (x - 1) / 2;
	}
	cout << ans << endl;
}