#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k, w;
    cin >> n >> k >> w;
    string s;
    cin >> s;
    vector<int> c1(n);
    vector<int> c0(n);
    for (int i = 0; i < 2 * k; ++i) {
        c1.push_back(0);
        c0.push_back(0);
    }
    for (int i = n - 1; i >= 0; --i) {
        c1[i] = (s[i] == '1');
        c0[i] = (s[i] == '0');
        c1[i] += c1[i + k];
        c0[i] += c0[i + k];
    }
    
    for (int i = 0; i < w; ++i) {
        int l, r;
        cin >> l >> r;
        --l; 
        --r;
        int ans = 0;
        for (int j = 0; j < k; ++j) {
            int cc1 = c1[l + j] - c1[r + 1 + j];
            int cc0 = c0[l + j] - c0[r + 1 + j];
            
            if (j == k - 1) {
                ans += cc0;
            } else {
                ans += cc1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}