#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, a, b;
    cin >> t;
    for (int it=0;it<t;it++){
    cin >> a >> b;
    if (a - 1 != b){
        cout << "NO" << endl;
    }
    else{
        a+=b;
        bool ye = true;
        for (int i=2; i*i <= a; i++){
            if (a%i==0){
                cout << "NO" << endl;
                ye = false;
                break;
            }
        }
        if (ye) cout << "YES" << endl;
    }
    }
}