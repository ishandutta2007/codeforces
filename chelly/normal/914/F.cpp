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
#include<bitset>
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
const int N = 100000;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
bitset<N> msk[26];
int main() {
	string st;
	cin >> st;
	for(int i(0); i < (int)st.size(); i++) {
		msk[st[i] - 'a'].set(i);
	}
	int Q;
	scanf("%d", &Q);
	for(int i(0); i < Q; i++) {
		int tp;
		scanf("%d", &tp);
		if(tp == 2) {
			int le, ri;
			scanf("%d%d", &le, &ri);
			le--; ri--;
			string a;
			cin >> a;
			if(ri - le + 1 < (int)a.size()) {
				printf("0\n");
				continue;
			}
			bitset<N> tmp;
			tmp.set();
			for(int i(0); i < (int)a.size(); i++)
				tmp = tmp & (msk[a[i] - 'a'] >> (le + i));
			printf("%d\n", (int)(tmp << (N - (ri - le + 1 - (int)a.size() + 1))).count());
		}else {
			int le; char c;
			scanf("%d %c", &le, &c);
			msk[st[le - 1] - 'a'].set(le - 1, 0);
			msk[c - 'a'].set(le - 1, 1);
			st[le - 1] = c;
		}
	}
}