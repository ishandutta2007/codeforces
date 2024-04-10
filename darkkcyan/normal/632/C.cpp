#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& i: a) cin >> i;
    sort(a.begin(), a.end(), [](const string& u, const string& v) {
        return (u + v) < (v + u);
    });
    
    for (auto& i: a) cout << i;
    
    return 0;
}