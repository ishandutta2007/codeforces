#include <bits/stdc++.h>
#define int long long
using namespace std;
string read(){
    string kek;
    cin >> kek;
    return kek;
}
int32_t main(){
    int n;
    cin >> n;
    cout << 0 << " " << 0 << endl;
    string colour = read();
    int L = 1, R = 1e9;
    for (int i=0; i < n-1; i++){
        int len = (R-L+1);
        int coord = len/2;
        int pt = L+coord;
        cout << 0 << " " << pt << endl;
        string c = read();
        if (c == colour){
            L = pt+1;
        }
        else{
            R = pt-1;
        }
    }
    if (L <= R) cout << 0 << " " << L << " " << 1 << " " << L << endl;
    else{
        if (R > 10){
            cout << 1 << " " << R-1 << " " << 3 << " " << R-4 << endl;
        }
        else{
            cout << 1 << " " << R+1 << " " << 3 << " " << R+2 << endl;
        }
    }

}