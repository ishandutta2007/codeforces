#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    int ac = 0;
    for(int i=0;i<s.size();++i) {
        ac += s[i] == 'a';
    }
    ac = min(ac*2-1, (int)s.size());
    cout << ac << endl;
    return 0;
}