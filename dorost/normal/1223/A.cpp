#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        if(n == 2){
            cout << 2;
        }else {
            cout << n % 2;
        }
        cout << endl;
    }
}