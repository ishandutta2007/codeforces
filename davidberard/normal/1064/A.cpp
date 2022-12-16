#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    cout << max(v[2]+1-(v[0]+v[1]), 0) << endl;
    return 0;
}