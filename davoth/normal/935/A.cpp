#include <bits/stdc++.h>
using namespace std;
const int si=1e5+10;
int main() {
    int n;
    cin >> n;
    int r=0;
    for(int i=2; i<=n; i++){
        if(n%i==0) r++;
    }
    cout << r;
    return 0;
}