#include <iostream>
#include <cmath>
#include <map>
#define p 998244353
using namespace std;
int K;
struct matrix{
	int mat[102][102];

	matrix operator * (const matrix &x) const{
		matrix ans;
		for (int j = 1; j <= K; ++ j)
			for (int i = 1; i <= K; ++ i){
				ans.mat[i][j] = 0;
				for (int k = 1; k <= K; ++ k){
					ans.mat[i][j] += 1LL * mat[i][k] * x.mat[k][j] % (p - 1);
					if (ans.mat[i][j] >= p - 1)
						ans.mat[i][j] -= p - 1;
				}
			}
		return ans;
	}
	void fpw(int y){
		matrix x = *this, ans;
		for (int i = 1; i <= K; ++ i)
			for (int j = 1; j <= K; ++ j)
				ans.mat[i][j] = i == j;
		for (int i = 1; i <= y; i <<= 1, x = x * x)
			if (y & i)
				ans = ans * x;
		*this = ans;
	}
}A;

int fpw(int x, int y){
	int ans = 1;
	for (int i = 1; i <= y; i <<= 1, x = 1LL * x * x % p)
		if (y & i)
			ans = 1LL * ans * x % p;
	return ans;
}
map <int, int> mp;
int BSGS(int a, int b){
	int n = fpw(a, p - 2), m = sqrt(p);
	for (int i = 0, c = 1; i < m; ++ i, c = 1LL * c * n % p){
		mp[1LL * b * c % p] = i;
		//cout << 1LL *b * c % p << " ";
	}
	//cout << endl << endl;
	int x = fpw(a, m);
	for (int i = 0, c = 1; i <= p / m; ++ i, c = 1LL * c * x % p){
		//cout << c << " ";
		if (mp.count(c))
			return i * m + mp[c];
	}
	return -1;
}
int gcd(int x, int y){
	if (y == 0)
		return x;
	return gcd(y, x % y);
}
void exgcd(int a, int b, int &x, int &y){
	if (b == 0){
		x = 1;
		y = 0;
		return;
	}
	int tx, ty;
	exgcd(b, a % b, tx, ty);
	x = ty;
	y = tx - a / b * ty;
}
int b[102];
int main(){
	int n, hn;
	cin >> K;
	for (int i = 1; i <= K; ++ i){
		cin >> b[i];
		b[i] %= p - 1;
	}
	cin >> n >> hn;
	for (int i = 1; i <= K; ++ i)
		A.mat[1][i] = b[i];
	for (int i = 2; i <= K; ++ i)
		A.mat[i][i - 1] = 1;
	A.fpw(n - K);
	hn = BSGS(3, hn);
	int c = A.mat[1][1], hk = 0, x = 0;
	//c*hk+(p-1)*x=hn
	int r = gcd(c, p - 1);
	if (hn == -1 || hn % r)
		cout << -1 << endl;
	else{
		int t = p - 1;
		c /= r, t /= r, hn /= r;
		exgcd(c, t, hk, x);
		hk = 1LL * hk * hn % t;
		hk = (hk + t) % t;
		cout << fpw(3, hk) << endl;
	}
}