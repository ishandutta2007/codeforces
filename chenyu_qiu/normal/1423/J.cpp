#include<iostream>
#include<cstring>
using namespace std;
using LL = long long;
 
const int mod = 1e9 + 7;
 
void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}
 
const int M = 10;
int f[62][M];
 
int main(){
 
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
 
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
 
	int T;
	cin >> T;
	while(T--){
		LL n;
		cin >> n;
		cout << (int)((__int128(n + 1) * ((n & 1 ? -1 : 1) + n + 6) + 9) / 16 % mod) << '\n';
	}
	// 
 
}