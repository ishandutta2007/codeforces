#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
int n, r;
signed main() {
    cout.precision(20);
    //freopen("1.txt", "r", stdin);
    //srand(time(NULL));
    cin >> n >> r;
    vector<int> v((1<<n));
    int S = 0;
    for (int i=0; i < (1<<n); i++){
        cin >> v[i];
        S += v[i];
    }
    cout << (double) S / (double) (1<<n) << endl;
    for (int i=0; i < r; i++){
        int ind, x;
        cin >> ind >> x;
        S += x - v[ind];
        v[ind] = x;
        cout << (double) S / (double) (1<<n) << endl;
    }
    return 0;
}