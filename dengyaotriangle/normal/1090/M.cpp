#include <bits/stdc++.h>
#define dbg(x) cout << #x " = " << x << "\n"
#define all(x) x. begin() , x . end()
#define abs(x) ((x>=0)?x:-x)
#define sqr(x) ((x)*(x))
#define siz(x) x.size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define il inline
#define y0 lkhklhhkukgasdxcsasdwre
#define y1 ajsodihousejbkrjykuasyi
using namespace std;
const int mod = (int)(1e9 + 7);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
il int read() {
	int f = 1 , x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();};
	return f * x;
}
il void print(int x) {
	if(x < 0) putchar('-') , x = -x;
	if(x >= 10) print(x / 10); putchar(x % 10 + 48);
}
template <typename T> bool Chkmax(T &a , T b) {return a < b ? a = b , 1 : 0;}
template <typename T> bool Chkmin(T &a , T b) {return a > b ? a = b , 1 : 0;}
void add(int &x , int y) {x = ((x % mod) + (y % mod)) % mod;}
void sub(int &x , int y) {x = ((x - y) % mod + mod) % mod;}
void mul(int &x , int y) {x = (ll)(x * y) % mod;}

const int Maxn = 200000 + 10;
int n , k;
int a[Maxn];
int dp[Maxn];
int main() {
	n = read() , k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	
	for(int i = 1; i <= n; i++) {
		if(a[i] == a[i - 1]) dp[i] = 1;
		else dp[i] = dp[i - 1] + 1;
	}
	
	cout << *max_element(dp + 1 , dp + n + 1);
	return 0;
}