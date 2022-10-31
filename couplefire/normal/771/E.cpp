#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ar array<int, 2>

const int N = 300005;
const int INF = 1000000009;

int n;
int arr[3][N], p[3][N], psum[N], f[N];
map<int, int> mp;
map<ar, int> dp;

void init(int* arr, int* p){
    for(int i = 1; i<=n; i++)
        psum[i] = psum[i-1]+arr[i];
    mp.clear(); mp[0] = 0;
    for(int i = 1; i<=n; i++){
        p[i] = p[i-1];
        if(mp.count(psum[i]))
            p[i] = max(p[i], mp[psum[i]]+1);
        mp[psum[i]] = i;
    }
}

int calc(int x, int y){
    if(x<0 || y<0) return -INF;
    if(x==y) return f[x];
    if(dp.count(ar{x, y})) return dp[{x, y}];
    int& ans = dp[{x, y}];
    ans = max(ans, f[min(x, y)]);
    if(x>y) ans = max(ans, calc(p[0][x]-1, y)+1);
    else ans = max(ans, calc(x, p[1][y]-1)+1);
    return ans;
}

signed main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++)
        cin >> arr[0][i];
    for(int i = 1; i<=n; i++)
        cin >> arr[1][i];
    for(int i = 1; i<=n; i++)
        arr[2][i] = arr[0][i]+arr[1][i];
    for(int i = 0; i<3; i++)
        init(arr[i], p[i]);
    for(int i = 1; i<=n; i++){
        f[i] = f[i-1];
        if(p[2][i]) f[i] = max(f[i], f[p[2][i]-1]+1);
        f[i] = max(f[i], calc(p[0][i]-1, i)+1);
        f[i] = max(f[i], calc(i, p[1][i]-1)+1);
    }
    cout << f[n] << endl;
}