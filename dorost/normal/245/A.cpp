#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, f, s, u, a[2] = {}, b[2] = {};
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> f >> s >> u;
        a[f - 1] += s;
        b[f - 1] += u;
    }
    cout << (b[0] > a[0] ? "DEAD\n" : "LIVE\n");
    cout << (b[1] > a[1] ? "DEAD" : "LIVE");
}