#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int l, r;
    cin >> l >> r;
    cout << "YES" << endl;
    for (int i=l; i < r; i+=2){
        cout << i << " " << i+1 << endl;
    }
}