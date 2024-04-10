#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int a=0, b=0;
    for (int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if (x > 0) a++;
        else b++;
    }
    if (min(a, b) <= 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}