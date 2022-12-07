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
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
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
const int N = 5055;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
short c[2][N][N], m[2][N][N];
int s1[N], s2[N], s3[N];
int main() {
	string s;
	cin >> s;
	int n = s.size();
	for(int i(0); i < n; i++) {
		for(int delta = -1; delta <= 1; delta += 2) {
			int cur(0), mn(0);
			for(int j(i); j < n; j++) {
				cur += s[j] == '(' ? 1 : s[j] == ')' ? -1 : delta;
				mn = min(mn, cur);
				c[(delta + 1) / 2][i][j] = cur;
				m[(delta + 1) / 2][i][j] = mn;
				//printf("m[%d][%d][%d] = %d\n", delta + 1, i, j, m[delta + 1][i][j]);
			}
		}
	}
	for(int i(1); i <= n; i++) {
		s1[i] = s1[i - 1] + (s[i - 1] == '(');
		s2[i] = s2[i - 1] + (s[i - 1] == ')');
		s3[i] = s3[i - 1] + (s[i - 1] == '?');
	}
	int ans = 0;
	for(int i(0); i < n; i++) {
		int k(i);
		for(int j(i + 1); j < n; j += 2) {
			while(k <= j && (s1[j + 1] - s1[i]) - (s2[j + 1] - s2[i]) + (s3[k + 1] - s3[i]) - (s3[j + 1] - s3[k + 1]) < 0)
				k++;
			if(k == j + 1) continue;
			ans += (c[1][i][k] + c[0][k + 1][j] == 0)  && (m[1][i][k] >= 0) && (c[1][i][k] + m[0][k + 1][j] >= 0);
			//printf("%d %d\n", i, j);
		}
	}
	cout << ans << endl;
}