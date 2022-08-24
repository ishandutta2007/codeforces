#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n;
    cin >> n;
    vector<int> sv(n);
    fill(sv.begin(), sv.end(), 0);
    for (int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        sv[a-1]++;
        sv[b-1]++;
    }
    int pr=0;
    for (int i=0;i<n;i++) pr += (sv[i] == 1);
    cout << pr << endl;
    return 0;
}