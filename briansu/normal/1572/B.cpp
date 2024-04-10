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

const int MAXn = 2e5 + 5;

int a[MAXn];

vector<int> his;
int n;
void apply(int x) {
    assert(x >= 1 && x <= n - 2);
    his.pb(x);
    int s = a[x] + a[x + 1] + a[x + 2];
    a[x] = a[x + 1] = a[x + 2] = (s&1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        int sum = 0;
        cin >> n;
        for (int i = 0; i <= n + 2; i++)
            a[i] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], sum += a[i];
        if (sum & 1) {
            cout << "NO\n";
            continue;
        }
        his.clear();
        int lst = -1, tt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                if (tt != 0) {
                    if (tt&1) {
                        int j = i - 1;
                        for (; !a[j + 1] && !a[j + 2]; j += 2)
                            apply(j);
                        if (!a[j + 1]) {
                            apply(j);
                            for (int k = j - 2; k >= 0 && a[k]; k -= 2)
                                apply(k);
                        }
                        else {
                            if (lst == -1) {
                                tt++;
                                continue;
                            }
                            for (int k = lst; k + 2 <= n && a[k + 2]; k += 2)
                                apply(k); 
                        }
                    }
                    else {
                        for (int j = i - 2; j >= 0 && a[j]; j -= 2)
                            apply(j);
                    }
                }
                tt = 0;
                lst = i;
            }
            else ++tt;
        }
        if (tt) {
            assert(tt % 2 == 0);
            if (lst == -1) {
                cout << "NO\n";
                continue;
            }
            for (int j = lst; j + 2 <= n && a[j + 2]; j += 2)
                apply(j);
        }
        assert(SZ(his) <= n);
        cout << "YES\n";
        cout << SZ(his) << "\n";
        for (int i = 0; i < SZ(his); i++)
            cout << his[i] << " \n"[i == SZ(his) - 1];
    }
    
}