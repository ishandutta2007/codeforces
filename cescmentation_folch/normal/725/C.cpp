#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<ll> vll;

int cnt[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    string b;
    cin >> a;
    for (int i = 1; i < 27; ++i) {
        if (a[i] == a[i - 1]) {
            cout << "Impossible" << '\n';
            return 0;
        }
    }
    int j;
    int t;
    for (int i = 0; i < 27; ++i) {
        int k = a[i] - 'A';
        if (cnt[k]) {
          j = cnt[k] - 1;
          t = 12 - (i - j - 1)/2;
        }
        else {
            cnt[k] = i + 1;
            b.push_back(a[i]);
        }
    }
//     cerr << j << ' ' << t << '\n';
    char S[26];
    for (int i = 0; i < 26; ++i) {
        S[(t + i)%26] = b[(j + i)%26];
    }
    for (int i = 0; i < 13; ++i) cout << S[i];
    cout << '\n';
    for (int i = 25; i >= 13; --i) cout << S[i];
    cout << '\n';
}