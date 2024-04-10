#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int N = 0;
    map<int, int> q;
    for (int i=0; i < n; i++){
        int A;
        cin >> A;
        q[A]++;
        if (q[A] % 2 != 0) N++;
        else N--;
    }
    if (N == 0) cout << "Agasa" << endl;
    else cout << "Conan" << endl;
    return 0;
}