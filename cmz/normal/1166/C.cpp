#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long

using namespace std;
int kkkkk; 
inline ll read(){
    ll x = 0; int zf = 1; char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') zf = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar(); return x * zf;
}
 
ll a[200005];
 
int main(){
	int n = read(); int aa=0;
	for (int i = 1; i <= n; ++i)
		a[i] = abs(read());
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for (int i = 1; i <= n; ++i){
		int l = i + 1, r = n, k = -1, val = a[i] << 1;
		while (l <= r){
			int mid = (l + r) >> 1;
			if (a[mid] <= val){
				l = mid + 1;
				k = mid;
			}
			else
				r = mid - 1;
		}
		if (k != -1)
			ans += k - i;
	}
	printf("%I64d", ans);
	return 0;
}