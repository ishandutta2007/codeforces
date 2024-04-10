#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, s;
int f[10050][250];
int main() {
	memset(f, 0x80, sizeof(f));
	f[0][0]=0;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) {
		long long p; int x=0, y=0; scanf("%I64d", &p);
		for(; !(p%5); p/=5) ++x;
		for(; !(p%2); p/=2) ++y;
		s+=x;
		for(int k=min(i, m); k>=1; --k)
			for(int j=s; j>=x; --j)
				f[j][k]=max(f[j][k], f[j-x][k-1]+y);
	}
	int ans=0;
	for(int i=1; i<=s; ++i) ans=max(ans, min(i, f[i][m]));
	printf("%d\n", ans);
	return 0;
}