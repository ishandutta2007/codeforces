#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;
    
    int l = 0;
    for (int i = 0; i < t; ++i) {
        l += v1;
        int rt = t - i - 2;
        for (int cd = d; cd >= -d; --cd) {
            if (abs((v1 + cd) - v2) <= rt * d) {
                v1 += cd;
                break;
            }
        }
    }
    
    cout << l << endl;
    
    return 0;
}