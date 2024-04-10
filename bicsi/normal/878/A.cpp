#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    
    vector<int> V(n);
    vector<char> Op(n);

    for (int i = 0; i < n; ++i) {
        cin >> Op[i];
        cin >> V[i];
    }

    vector<int> Map0(10), Map1(10);
    for (int bit = 0; bit < 10; ++bit) {
        Map1[bit] = 1;
        for (int i = 0; i < n; ++i) {
            int with = !!(V[i] & (1 << bit));
            char op = Op[i];

            if (op == '|') { Map0[bit] |= with; Map1[bit] |= with; }
            if (op == '^') { Map0[bit] ^= with; Map1[bit] ^= with; }
            if (op == '&') { Map0[bit] &= with; Map1[bit] &= with; }
        }    
    }
    
    for (int bit = 0; bit < 10; ++bit) {
        cerr << Map0[bit] << " " << Map1[bit] << endl;
    }

    int orX = 0, andX = 0, xorX = 0;
    for (int bit = 0; bit < 10; ++bit) {
        bool b0 = Map0[bit], b1 = Map1[bit];
        if (!b0 && !b1) continue;
        if (b0 && b1) { orX |= (1 << bit); andX |= (1 << bit); continue; }
        if (b0 && !b1) { xorX |= (1 << bit); andX |= (1 << bit); continue; }
        if (!b0 && b1) { andX |= (1 << bit); continue; }
    }

    cout << 3 << endl;
    cout << "| " << orX << endl;
    cout << "^ " << xorX << endl;
    cout << "& " << andX << endl;

    return 0;
}