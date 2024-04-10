#include<bits/stdc++.h>
const int N = 2e5 + 5;
using namespace std;

int n, a[N], b[N], p[N], q[N];
int ans[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], p[i] = q[i] = i;
    for (int i = 1; i <= n; i++) cin >> b[i];
    sort(p+1, p+1+n, [](int x, int y){return a[x] < a[y];});
    sort(q+1, q+1+n, [](int x, int y){return b[x] > b[y];});
    for (int i = 1; i <= n; i++) ans[q[i]] = a[p[i]];
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}