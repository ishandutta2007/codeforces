#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n==0){
        cout << 0;
        return 0;
    }
    n++;
    if (n %2 != 0){
        cout << n;
        return 0;
    }
    cout << n/2;
}