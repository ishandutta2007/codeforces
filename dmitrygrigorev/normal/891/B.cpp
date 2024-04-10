#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i < n; i++) cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    for (int i=0; i < n; i++){
        int ind;
        for (int j=0; j < n; j++){
            if (b[j] == a[i]) ind = j;
        }
        if (ind == n-1) a[i] = b[0];
        else a[i] = b[ind+1];
    }
    for (int i=0; i < n; i++) cout << a[i] << " ";
    return 0;
}