#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int x;
    cin >> x;
    return x;
}

void tell(int x) {
    cout << "! " << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(1<<n);
        iota(v.begin(), v.end(), 1);
        while((int)v.size() > 2) {
            vector <int> nv;
            while(!v.empty()) {
                vector <int> w;
                for(int i = 0; i < 4; i++) {
                    w.push_back(v.back());
                    v.pop_back();
                }
                int x = ask(w[0], w[2]);
                if(x == 0) {
                    x = ask(w[1], w[3]);
                    nv.push_back((x == 1) ? w[1] : w[3]);
                } else if(x == 1) {
                    x = ask(w[0], w[3]);
                    nv.push_back((x == 1) ? w[0] : w[3]);
                } else {
                    x = ask(w[1], w[2]);
                    nv.push_back((x == 1) ? w[1] : w[2]);
                }
            }
            v = nv;
        }
        if((int)v.size() == 2) {
            int x = ask(v[0], v[1]);
            if(x == 1) tell(v[0]);
            else tell(v[1]);
        } else {
            tell(v[0]);
        }
    }
    
    return 0;
}