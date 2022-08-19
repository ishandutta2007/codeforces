#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

int n, q;
bitset<7005> st[100005];
int mu[7005];
bitset<7005> divs[7005], muls[7005];
char ret[1000005];
int cnt = 0;

int main()
{
	scanf("%d%d", &n, &q);
	
	mu[1] = 1;
	rep1(i, 7000) for(int j = i * 2; j <= 7000; j += i) mu[j] -= mu[i];
	rep1(i, 7000) for(int j = i; j <= 7000; j += i) {
		if(mu[j / i]) muls[i][j] = true;
		divs[j][i] = true;
	}
	
	rep(i, q) {
		int t;
		scanf("%d", &t);
		if(t == 1) {
			int x, v;
			scanf("%d%d", &x, &v);
			st[x] = divs[v]; 
		} else if(t == 2) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			st[x] = st[y] ^ st[z];
		} else if(t == 3) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			st[x] = st[y] & st[z];
		} else if(t == 4) {
			int x, v;
			scanf("%d%d", &x, &v);
			ret[cnt ++] = '0' + ((st[x] & muls[v]).count() & 1);
		}
	}
	printf("%s\n", ret);
	return 0;
}