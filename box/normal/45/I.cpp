#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> negative;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    bool first = true;
    bool zero = false;
    for(int i=0; i<n; i++) {
        int v; cin >> v;
        if(v > 0) {
            if(!first) cout << ' ';
            cout << v; first = false;
        }
        else if(v == 0) zero = true;
        else {
            negative.push_back(v);
        }
    }
    if(first) {
        if(zero && negative.size() <= 1) cout << 0;
        else if(negative.size() == 1) cout << negative[0];
    }
    sort(negative.begin(), negative.end());
    for(int i=0; 2*i+2<=negative.size(); i++) {
        if(!first || i != 0) cout << ' ';
        cout << negative[2*i] << ' ' << negative[2*i+1];
    }
    cout << endl;
}