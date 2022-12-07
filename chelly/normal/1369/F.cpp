#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
mt19937 gene(233);
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
	const int maxn = 131072;
	static char buf[maxn],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline LL fastpo(LL x, LL n, LL mod) {
	LL res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}

inline string itoa(int x, int width = 0) {
  string res;
  if(x == 0) res.push_back('0');
  while(x) {
    res.push_back('0' + x % 10);
    x /= 10;
  }
  while((int)res.size() < width) res.push_back('0');
  reverse(res.begin(), res.end());
  return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
	fwrite(buf, 1, _bl, stdout);
	_bl = 0;
}
__inline void _putchar(char c) {
	if(_bl == _B) flush();
	buf[_bl++] = c;
}
inline void print(LL x, char c) {
	static char tmp[20];
	int l = 0;
	if(!x) tmp[l++] = '0';
	else {
		while(x) {
			tmp[l++] = x % 10 + '0';
			x /= 10;
		}
	}
	for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
	_putchar(c);
}
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int checkl(LL x, LL y);
int check(LL x, LL y) {
	assert(x <= y);
	if(y % 2 == 0) {
		if(x * 2 > y) {
			return (y - x) % 2 == 1;
		}else {
			return checkl(x, y / 2);
		}
	}else return (y - x) % 2 == 1;
}
int checkl(LL x, LL y) {
	assert(x <= y);
	if(x * 2 > y) {
		return 1;
	}else {
		return check(x, y / 2);
	}
}
int fl[N], fw[N], sw[N], sl[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		LL x, y;
		cin >> x >> y;

		fw[i] = check(x, y);

		sw[i] = !fw[i];


		fl[i] = checkl(x, y);

		sl[i] = !fl[i];
	//	printf("%d %d %d %d\n", fw[i], sw[i], fl[i], sl[i]);

	}
	int target = 1;
	int aw;
	for(int i = n; i >= 1; i--) {
		if(target) {
			if(fw[i] && sw[i]) {
				aw = true;
				break;
			}else if(fw[i]) {
				target = 0;
			}else if(sw[i]) {
				target = 1;
			}else {
				aw = false;
				break;
			}
		}else {
			if(fl[i] && sl[i]) {
				aw = true;
				break;
			}else if(fl[i]) {
				target = 0;
			}else if(sl[i]) {
				target = 1;
			}else {
				aw = false;
				break;
			}
		}
		if(i == 1) {
			aw = target == 0;
		}
	}

	int al;
	target = 0;
	for(int i = n; i >= 1; i--) {
		if(target) {
			if(fw[i] && sw[i]) {
				al = true;
				break;
			}else if(fw[i]) {
				target = 0;
			}else if(sw[i]) {
				target = 1;
			}else {
				al = false;
				break;
			}
		}else {
			if(fl[i] && sl[i]) {
				al = true;
				break;
			}else if(fl[i]) {
				target = 0;
			}else if(sl[i]) {
				target = 1;
			}else {
				al = false;
				break;
			}
		}
		if(i == 1) {
			al = target == 0;
		}
	}
	cout << aw << ' ' << al << endl;

}