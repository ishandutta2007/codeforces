#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    bool ans[n];
    for (int i=0; i < n; i++) ans[i] = false;
    vector<int> pos(n);
    for (int i=0; i < n; i++) pos[a[i]-1] = i;
    for (int i=n-1; i >= 0; i--){
        int p = pos[i];
        for (int j=(i+1); j <= n; j+=(i+1)){
            int L = p - j, R = p+j;
            if (L >= 0 && L < n && !ans[L] && (a[L] > a[p])) ans[p] = true;
            if (R >= 0 && R < n && !ans[R] && (a[R] > a[p])) ans[p] = true;
        }
    }
    for (int i=0;i<n;i++){
        if (ans[i]) cout << "A";
        else cout << "B";
    }
}