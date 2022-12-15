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

const int MAXn = 1e6 + 5, C = 20;

int a[MAXn];

int mp[2][MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;

    for (int L = C - 1; L >= 0; L--) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < MAXn; j++)
                mp[i][j] = n + 2;
        int rmst = n, cur = 0;
        mp[(n + 1)&1][0] = n + 1;
        for (int i = n; i >= 1; i--) {
            cur ^= (a[i] >> (L + 1));
            if (!((a[i] >> L)&1))
                rmst = i - 1;
            else {
                int t = mp[(i&1)][cur];  
                if (t <= rmst + 1)
                    ans = max(ans,  t - i);
            }
            if (mp[(i&1)][cur] > rmst + 1)
                mp[(i&1)][cur] = i;
        }
    }

    cout << ans << endl;
        
}