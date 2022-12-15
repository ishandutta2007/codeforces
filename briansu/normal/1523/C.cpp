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

const int MAXn = 1e3 + 5;

int a[MAXn], dt[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1)
                v.pb(a[i]);
            else {
                while (v.back() + 1 != a[i])
                    v.pop_back();
                v.back()++;
            }
            for (int i = 0; i < SZ(v); i++)
                cout << v[i] << ".\n"[i == SZ(v) - 1];
        }
        
    }
    
}