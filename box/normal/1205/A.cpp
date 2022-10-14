#include <iostream>
using namespace std;

int aray[200005];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    if(n % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i=0; i<n; i++) {
        if(i%2) {
            aray[i] = 2*i+1;
            aray[n+i] = 2*i+2;
        } else {
            aray[i] = 2*i+2;
            aray[n+i] = 2*i+1;
        }
    }
    for(int i=0; i<2*n; i++) {
        if(i != 0) cout << ' ';
        cout << aray[i];
    }
    cout << endl;
}