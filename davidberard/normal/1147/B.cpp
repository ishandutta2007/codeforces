#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 100100;

vector<int> of[NMAX];
unordered_set<int> good;

int n, m;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        if(b > a) swap(a, b);
        int l1 = a-b;
        int l2 = b+n-a;
        if(l1 == l2) {
            of[l1].push_back(a);
            of[l1].push_back(b);
            //cerr << " " << l1 << endl;
        } else if(l1 < l2) {
            of[l1].push_back(b);
            //cerr << " " << l1 << endl;
        } else if(l2 < l1) {
            of[l2].push_back(a);
            //cerr << " " << l2 << endl;
        }
    }
    for(int i=1; i<=n; ++i) {
        if(i > n/2) assert(of[i].size() == 0);
        sort(of[i].begin(), of[i].end());
    }
    for(int i=1; i<=n/2; ++i) {
        if(!of[i].size()) continue;
        vector<int> diff;
        for(int j=0;j<of[i].size()-1;++j) {
            diff.push_back(of[i][j+1]-of[i][j]);
        }
        diff.push_back(n+of[i][0]-of[i].back());
        of[i] = diff;
    }
    for(int i=1; i<=n/2; ++i) {
        good.insert(i);
    }
    for(int i=1; i<=n/2; ++i) {
        if(!of[i].size()) continue;
        int z = of[i].size();
        //cerr << " for len " << i << " we have " << z << " edges " << endl;
        vector<int> fac;
        for(int j=1; j*j<=z; ++j) {
            if(z%j != 0) continue;
            fac.push_back(j);
            if(j == z/j) continue;
            fac.push_back(z/j);
        }
        vector<int> gfac;
        //cerr << endl;
        for(auto& x : fac) {
            if(x == z) continue;
            //cerr << " " << x << " is a divisor " << endl;
            for(int j=0; j<z/x; ++j) {
                for(int k=0; k<x; ++k) {
                    //cerr << " " << of[i][j*x+k] << " vs " << of[i][k] << endl;
                    if(of[i][j*x+k] != of[i][k]) goto bad;
                }
            }
            gfac.push_back((ll) n*x/z);
bad:;
        }
        unordered_set<int> rep;
        for(auto& x : gfac) {
            //cerr << " good " << x << endl;
            if(good.count(x)) rep.insert(x);
        }
        good = rep;
    }
    if(good.size()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}