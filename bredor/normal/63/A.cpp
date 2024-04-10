//  228

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;


#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector <int>
#define dbg(var) cout << "[" << #var << " : " << var << "]\n"
int64_t mod = 1000000007;


void rv(vector<ll> &a) {
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.precision(7);
    int n;
    cin >> n;
    vector<string> ans;
    vector<string> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] == "rat") {
            ans.push_back(a[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] == "woman" or b[i] == "child") {
            ans.push_back(a[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] == "man") {
            ans.push_back(a[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == "captain") {
            ans.push_back(a[i]);
        }
    }
    for (auto c : ans) {
        cout << c << "\n";
    }
    // cout << "\nTime elapsed: " << 1.000 * clock() / CLOCKS_PER_SEC << " ms. \n";
    return 0;
}