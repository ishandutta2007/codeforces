#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    int a = 1, b = 2;
    for (int i=0; i < n; i++){
        int x;
        cin >> x;
        if (a != x && b != x){
            cout << "NO" << endl;
            return 0;
        }
        int free;
        if (a != 3 && b != 3) free=3;
        if (a != 2 && b != 2) free=2;
        if (a != 1 && b != 1) free=1;
        if (a == x) b = free;
        else a = free;

    }
    cout << "YES" << endl;
    return 0;
}