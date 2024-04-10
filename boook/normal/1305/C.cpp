#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 200000 + 100
#define inf 0x3f3f3f3f

int n, m, x[maxn], ttt[maxn];
long long cnt[maxn];
int ppow(int a , long long k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(a * a % m , k >> 1);
    if(k % 2 == 1) return ppow(a * a % m , k >> 1) * a % m;
}
int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> x[i];
    sort(x + 1, x + 1 + n);
    for (int i = 1; i <= n; ++ i) {
        x[i] %= m;
        for (int j = 0; j < m; ++ j) 
            cnt[x[i] - j + m] += ttt[j];
        ttt[x[i] % m] ++;
    }
    int ans = 1;
    for (int i = 0; i < m + m; ++ i) {
        ans = ans * ppow(i, cnt[i]) % m;
    }
    cout << ans << endl;
    return 0;
}