#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll g = 0;
        for (int j = 0; j < 30; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++)
                if ((a[i]>>j)&1)
                    cnt++;
            g = gcd(g, cnt);
        }
        for (int i = 1; i <= n; i++)
            if (g % i == 0)
                cout << i << " ";
        cout << endl;
    }
        
}