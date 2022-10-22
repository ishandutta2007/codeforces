#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,a,b,l=10000;
    cin >> n >> m >> a >> b;
    for(int i = m; i*a>b && i>0; i--) {
        l=i;
    }
    int r=0;
    for(int i=m; i>=l; i--){
        r+=n/i*b;
        n%=i;
    }
    cout << r+n*a;
    return 0;
}