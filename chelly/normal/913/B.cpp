#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
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
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
typedef vector<pair< pair<int, int>, pair<int, int> > > vppiipii;
vppiipii dp[4444];
int a[99];
int fa[N], cnt[N], num[N];
int main() {

	int n;
	scanf("%d", &n);
	for(int i(2); i <= n; i++){
		scanf("%d", &fa[i]);
		cnt[fa[i]]++;
	}
	for(int i(2); i <= n; i++){
		if(cnt[i] == 0){
			num[fa[i]]++;
		}
	}
	bool flag(true);
	for(int i(1); i <= n; i++){
		if(cnt[i] != 0 && num[i] < 3){
			flag = false;
		}
	}
	printf("%s\n", flag ?"YES":"NO");
}