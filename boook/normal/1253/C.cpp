#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 200090;

int n, k, x[maxn], y[maxn], ans[maxn];

int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> n >> k;

    for (int i = 1; i <= n; i ++) cin >> x[i];

    sort(x + 1, x + 1 + n);
    
    
    int base = 1;
    for (int i = 1; i <= n; i ++) {
        
        y[i % k] += x[i];
   
        ans[i] = ans[i - 1] + y[i % k]; 

    }

    for (int i = 1; i <= n; i ++)
        cout << ans[i] << " \n"[i == n];
    return 0;
}