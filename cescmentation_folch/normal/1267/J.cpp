#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int>v(n, 0);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            v[a-1]++;
        }
        vector <int>c(n+2, 0);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] != 0) {
                ++cnt;
                for (int s = 2; s <= v[i]+1; ++s) {
                    int a = v[i]/(s-1);
                    if (v[i]%(s-1) <= a) ++c[s];
                }
            }
        }
        int s = 2;
        for (int i = 3; i <= n+1; ++i) {
            if (c[i] == cnt) {
                s = i;
            }
        }
    
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (v[i]+s-1)/s;            
        }
            
        cout << ans << '\n';
    }
}