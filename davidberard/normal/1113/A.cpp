#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, v;
    cin >> n >> v;
    int m = max(n-v, 0);
    m = m*(m+1)/2-1;
    m += min(v, n);
    cout << m << endl;
    return 0;
}