#include <bits/stdc++.h>
using namespace std;

struct can {
    int v, id;
    const bool operator<(const can other) const {
        return v > other.v;
    }
};

vector<can> aray;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int c; cin >> c;
    for(int i=0; i<c; i++) {
        int v; cin >> v;
        aray.push_back({v, i+1});
    }
    sort(aray.begin(), aray.end());
    int tot = 0, cum = 0;
    for(int i=0; i<c; i++) {
        tot += (aray[i].v*cum + 1);
        cum++;
    }
    cout << tot << endl;
    for(int i=0; i<c; i++) {
        if(i != 0) cout << ' ';
        cout << aray[i].id;
    }
    cout << endl;
}