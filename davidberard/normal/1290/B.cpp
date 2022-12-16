#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int N = 200100;
int st[N][26];
char s[N];

int toi(char c) {
    return c - 'a';
}

int count_diff(int x[26]) {
    int ans = 0;
    for (int i=0; i<26; ++i) {
        ans += (x[i] != 0);
    }
    return ans;
}

int count_diff(int l, int r) {
    int x[26];
    for (int i=0; i<26; ++i) {
        x[i] = st[r][i] - st[l-1][i];
    }
    int ans= count_diff(x);
    //cerr << " CD " << l << " -> " << r << " : " << ans << endl;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> (s+1);
    int n = strlen(s+1);
    for (int i=1; i<=n; ++i) {
        for (int j=0; j<26; ++j) {
            st[i][j] = st[i-1][j];
        }
        st[i][toi(s[i])]++;
    }
    int q;
    cin >> q;
    for (int i=1; i<=q; ++i) {
        int l, r;
        cin >> l >> r;
        bool good = false;
        if (l == r) {
            good = true;
        }
        if (s[l] != s[r]) {
            good = true;
        }
        if (count_diff(l, r) >= 3) {
            good = true;
        }
        cout << (good ? "Yes" : "No") << "\n";
    }

    return 0;
}