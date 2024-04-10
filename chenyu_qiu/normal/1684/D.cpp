#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
using namespace std;
 
const int N = 200010;
 
int n, k, a[N], id[N];
PII p[N];
 
void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        p[i] = { a[i] + i, i };
    }
    sort(p + 1, p + 1 + n, greater<PII>());
    for(int i = 1; i <= n && i <= k; i++) id[i] = p[i].second;
    sort(id + 1, id + 1 + min(n, k));
    
    int cnt = 0;
    LL res = 0;
    for(int i = 1; i <= n; i++) {
        if(cnt < k && i == id[cnt + 1]) ++ cnt;
        else res += a[i] + cnt;
    }
    cout << res << endl;
}
 
int main()
{
    int test;
    cin >> test;
    while(test--) solve();
 
    return 0;
}