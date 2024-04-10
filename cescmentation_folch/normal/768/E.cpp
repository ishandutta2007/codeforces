#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef map<ll, int> mll;
typedef vector<int> vi;

mll D[61];

int func(int p, ll mask) {
    if (D[p].count(mask) > 0) return D[p][mask];
    if (p == 0) return 0;
    vi V;
    for (int i = 1; i <= p; ++i) {
        if ((mask&(1<<i)) == 0) {
            V.push_back(func(p - i, mask | (1<<i))); 
        }
    }
    int k = 0;
    sort(V.begin(), V.end());
    for (int i = 0; i < (int)V.size(); ++i) {
        if (i and V[i] == V[i - 1]) continue;
        if (V[i] != k) break;
        ++k;
    }
    return D[p][mask] = k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
//     for (int i = 1; i <= 60; ++i) {
//         cout << func(i, 0) << " , ";
//     }
//     cout << endl;
    
    int R[61] = {0 , 1 , 1 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 , 5 , 5 , 5 , 5 , 5 , 5 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 9 , 9 , 9 , 9 , 9 , 9 , 9 , 9 , 9 , 9 , 10 , 10 , 10 , 10 , 10 , 10}; 

    
    int res = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        res ^= R[x];
    }
    if (res == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}