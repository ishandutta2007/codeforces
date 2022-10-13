#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

unordered_set<int> X, Y;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE


    int n, a, b;
    cin>>n;


    for(int i=1; i<=n; i++) {
        cin>>a>>b;
        X.insert(a);
        Y.insert(b);
    }

    vector<int> V;

    if(X.size() < 2 || Y.size() < 2) {
        cout<<-1;
    } else {
        for(auto p : X) {
            V.push_back(p);
        }
        for(auto p : Y) {
            V.push_back(p);
        }

        if(V[0] > V[1]) swap(V[0], V[1]);
        if(V[2] > V[3]) swap(V[2], V[3]);

        cout<<(V[1] - V[0])*(V[3] - V[2]);

    }





    return 0;
}