#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int k, n, s, p;
    cin >> k >> n >> s >> p;
    int i=1;
    int L = 0, R = 1e10;
    while (R-L>1){
        int M = (L+R) / 2;
        int lst = (M*p) / k;
        lst *= s;
        if (lst >= n){
            R = M;
        }
        else L = M;
    }
    cout << R;
}