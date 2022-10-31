#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+50;
typedef long long LL;
int n;
LL a[maxn],b[maxn],f[maxn];
LL mul[maxn],add[maxn];
LL ans[maxn];
void init(){
	cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d",a+i);
    for (int i = 1; i <= n; i++) scanf("%d",b+i),f[i] = f[i - 1] + b[i];;
    f[n + 1] = (0x7fffffffffffll) + f[n];
}
void solve(){
	for (int i = 1; i <= n; i++) {
        int mid = upper_bound(f + i, f + n + 2, a[i] + f[i - 1]) - f - 1;
        mul[i] += 1;
        mul[mid + 1] -= 1;
        add[mid + 1] += a[i] + f[i - 1] - f[mid];
    }
    for (int i = 1; i <= n; i++) mul[i] = mul[i] + mul[i - 1];
    for (int i = 1; i <= n; i++) ans[i]= b[i] * mul[i] + add[i];
    for (int i=1;i<=n;i++){
    	printf("%I64d ",ans[i]);
    }
    cout<<endl;
}
int main() {
    init();
    solve();
	return 0;
}