#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    int x = sizeof(int)*8 - __builtin_clz(N);
    cout << x << endl;
    return 0;
}