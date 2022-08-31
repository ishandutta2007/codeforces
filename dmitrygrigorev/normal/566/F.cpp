#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000001;
int v[N];
int ans[N];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        v[x]++;
    }
    for (int i=1; i < N; i++){
        ans[i] = max(ans[i], v[i]);
        for (int j=i+i; j < N; j+=i) ans[j] = max(ans[j], ans[i] + v[j]);
    }
    int kok = 0;
    for (int i=1;i < N; i++) kok = max(kok, ans[i]);
    cout << kok;
}