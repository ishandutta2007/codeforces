#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    int n; cin >> n;
    cout << 2000 << endl;
    int s = n+1;
    cout << -1 << " ";
    for(int i = 0; i<1999; i++){
        int subtract = min(999999, s);
        cout << subtract+1 << " ";
        s -= subtract;
    }
}