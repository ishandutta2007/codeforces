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
        int x, ans = -1;
        cin >> x;
        for (int I = 0; I < (1<<10); I++) {
            int val = 0, sum = 0;
            for (int i = 0; i < 10; i++)
                if ((I>>i)&1)
                    val = val * 10 + i, sum += i;
            if (sum == x)
                if (ans == -1) ans = val;
                else ans = min(ans, val);
        }
        cout << ans << "\n";
    }
}