#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while (t--){
        int a,b,c,d,k;
        cin >> a >> b >> c >> d >> k;
        int f = (a + c - 1) / c, g = (b + d - 1) / d;
        if (f + g > k){
            cout << -1;
        }else {
            cout << f << ' ' << g;
        }
        cout << endl;
    }
}