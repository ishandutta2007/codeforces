#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool f(string& s, ll n, ll k) {
    if(2 * k > n * (n - 1)) {
        return false;
    }
    if(n == 1) {
        s += "()";
    } else if(2 * k <= (n - 1) * (n - 2)) {
        s += "()";
        return f(s, n - 1, k);
    } else {
        s += '(';
        f(s, n - 1, k - n + 1);
        s += ')';
    }
    return true;
}

int main() {
    ll n;
    ll k;
    cin >> n >> k;
    string s;
    if(f(s, n, k)) {
        cout << s << '\n';
    } else {
        cout << "Impossible\n";
    }
}