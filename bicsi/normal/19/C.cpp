#include <bits/stdc++.h>

using namespace std;

#define B 31981

int V[500000];
uint64_t Part[500000], Pow[500000];

unordered_map<int, vector<int>> Ap;
int e, b;

uint64_t getHash(int e, int l) {
    return Part[e] - Pow[l] * Part[e - l];
}

int main() {
    int n, val;
    cin>>n;

    Pow[0] = 1;
    b = 1;

    while(n--) {
        cin>>val;

        V[++e] = val;
        Part[e] = Part[e-1] * B + val;
        Pow[e] = Pow[e-1] * B;


        auto &X = Ap[val];

        X.push_back(e);

        for(int i=X.size()-2; i>=0; i--) {
            int pos = X[i];
            int sz = e - pos;

            if(pos - sz + 1 < b) break;

            if(getHash(e, sz) == getHash(pos, sz)) {
                b = pos + 1;
                break;
            }
        }
    }

    cout << e - b + 1 << '\n';
    for(int i=b; i<=e; i++)
        cout << V[i] << " ";
    return 0;
}