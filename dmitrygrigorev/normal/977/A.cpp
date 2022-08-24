#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i=0; i < k; i++){
        if (n%10!=0) n--;
        else n/=10;
    }
    cout << n;
    return 0;
}


/*

1
6 6
3 6
3 4
1 4
1 2
1 3
2 3

*/