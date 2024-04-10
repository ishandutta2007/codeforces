#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    map<int, int> kek;
    int xr=0;
    kek[0]=1;
    for (int i=0; i < n; i++){
        xr ^= v[i];
        int kk = xr;
        kk = min(kk, (1LL<<k)-1-kk);
        kek[kk]++;
    }
    int ans = 0;
    for (auto it=kek.begin(); it != kek.end(); it++){
        int num = (*it).second;
        int A = num/2;
        int B = num-A;
        ans += A*(A-1)/2;
        ans += B*(B-1)/2;
    }
    int nn = n*(n+1)/2;
    cout << nn-ans;

}