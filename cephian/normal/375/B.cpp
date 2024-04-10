#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
struct __test {} test;
using namespace std;
template <typename T>const __test &operator<<(const __test& d,
const T& v) {return cerr << "\033[31m" << v << "\033[0m",d;}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int g[5005][5005],n,m;
int n0[5005][5005],a[5005];
char s[5005];
int main() {
	// ios::sync_with_stdio(0); cin.tie(0);
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; ++i) {
		scanf("%s",s);
		for(int j = 0; j < m; ++j)
			g[i][j] = s[j]=='1';
	}
	for(int i = 0; i < n; ++i) {
		int p = m;
		for(int j = m-1; j >= 0; --j) {
			if(g[i][j] == 0) p = j;
			n0[i][j] = p;
		}
	}
	ll ans = 0;
	for(int j = 0; j < m; ++j) {
		for(int i = 0; i < n; ++i) {
			a[i] = n0[i][j];
		}
		sort(a,a+n);
		for(int k = 0; k < n; ++k) {
			ans = max(ans,1LL*(a[k]-j)*(n-k));
		}
	}
	printf("%I64d\n",ans);
}