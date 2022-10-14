#include <iostream>
using namespace std;

int bmap[64];
long long aray[200005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int t=0; t<n; t++) {
        long long v; cin >> v;
        aray[t] = v;
        for(int i=0; i<=62; i++) {
            //cout << v << ' ' << i << ' ' << ((v&(1ull<<i)) != 0ull && (v&((1ull<<i)-1ull)) == 0ull) << endl;
            if((v&(1ull<<i)) != 0ull && (v&((1ull<<i)-1ull)) == 0ull)
                bmap[i]++;
        }
    }
    int i = 0;
    for(int I=0; I<=62; I++)
        if(bmap[I] > bmap[i]) i = I;
    if(n == bmap[i]) {
        cout << 0 << endl;
        return 0;
    }
    cout << n-bmap[i] << endl;
    bool pr = false;
    for(int j=0; j<n; j++)
        if(!((aray[j]&(1ull<<i)) != 0ull && (aray[j]&((1ull<<i)-1ull)) == 0ull)) {
            if(pr) cout << ' ';
            pr = true;
            cout << aray[j];
        }
    cout << endl;
}