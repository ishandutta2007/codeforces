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

int n;
int a[105];
int query() {
    cout << "?";
    for (int i = 1; i <= n; i++)
        cout << " " << a[i];
    cout << endl;
    int k;
    cin >> k;
    return k;
}

int ans[105];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int lst = n;
    for (; lst > 1; lst--) {
        for (int i = 1; i < n; i++)
            a[i] = 1;
        a[n] = n + 2 - lst;
        if (query() == 0)
            break;
    }
    ans[n] = lst;
    for (int x = 1; x <= n; x++)
        if (x != lst) {
            for (int i = 1; i < n; i++)
                a[i] = n + 1 - x;
            a[n] = n + 1 - lst;
            int t = query();
            assert(t != 0);
            ans[t] = x;
        }
    cout << "!";
    for (int i = 1; i <= n; i++)
        cout << " " << ans[i];
    cout << endl;
     
    
}