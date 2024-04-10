#include <bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i=0; i < n; i++){
        int x;
        cin >> x;
        bool r = false;
        for (int j=0; j < 100; j++){
            int ost = x - 3*j;
            if (ost >= 0 && ost%7 == 0){
                cout << "YES" << endl;
                r = true;
                break;
            }
        }
        if (!r) cout << "NO" << endl;
    }
    return 0;
}