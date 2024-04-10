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

inline int fastpo(int x, int n, int mod) {
	int res(1);
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

const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[N], pre[N], suf[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i(1); i <= n; i++) {
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] | a[i];
	}
	int ans = -1, ansi;
	for(int i(n); i >= 1; i--) {
		suf[i] = suf[i + 1] | a[i];
		int tmp = (a[i] | pre[i - 1]) - pre[i - 1];
		tmp = (tmp | suf[i + 1]) - suf[i + 1];
		if(tmp > ans) {
			ansi = i;
			ans = tmp;
		}
	}
	vector<int> vec;
	vec.push_back(a[ansi]);
	for(int i = 1; i <= n; i++) if(i != ansi) vec.push_back(a[i]);
	for(int i = 0; i < n; i++) printf("%d%c", vec[i], i == n - 1 ? '\n' : ' ');
}