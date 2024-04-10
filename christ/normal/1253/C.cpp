#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MN = 2e5+1, INF = 2e9;
long long sum[MN];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> a(n);
    for (auto &au : a) scanf ("%d",&au);
    sort(a.begin(),a.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        sum[i%m] += a[i];
        ans += sum[i%m];
        printf ("%lld ",ans);
    }
	return !putchar(10);
}
//11649,6796