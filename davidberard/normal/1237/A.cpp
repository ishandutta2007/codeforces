#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;


const int N = 100100;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    int d = 0;
    for (int i=0; i<n; ++i) {
        if (a[i]%2 == 0) {
            cout << a[i]/2 << "\n";
        } else {
            if (a[i] > 0) {
                if (d) {
                    cout << a[i]/2+1 << "\n";
                    --d;
                } else {
                    cout << a[i]/2 << "\n";
                    ++d;
                }
            } else {
                if (d) {
                    cout << a[i]/2 << "\n";
                    --d;
                } else {
                    cout << a[i]/2-1 << "\n";
                    ++d;
                }
            }
        }
    }
    return 0;
}