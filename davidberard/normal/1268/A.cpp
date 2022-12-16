#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 200200;
char s[N];
int n, k;

void show() {
    if (s[0] == '1') {
        cout << n+1 << endl;
        for (int i=0; i<n; ++i) {
            cout << s[i%k];
        }
        cout << endl;
        return;
    }

    cout << n << endl;
    for (int i=0; i<n; ++i) {
        cout << s[(i%k) + 1];
    }
    cout << endl;
}

bool good() {
    for (int j=k; j<n; ++j) {
        if (s[j+1] < s[j%k+1]) return true;
        if (s[j+1] > s[j%k+1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    cin >> (s+1);
    if (good()) {
        show();
        return 0;
    }

    s[k] += 1;
    s[0] = '0';
    for (int j=k; j>=0; --j) {
        if (s[j] <= '9') break;
        s[j-1] += 1;
        s[j] -= 10;
    }

    show();
    return 0;
}