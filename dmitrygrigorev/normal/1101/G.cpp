#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans[40];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int x = 0, tet=0;
    for (int i=0; i < n; i++){
        int y;
        cin >> y;
        x ^= y;
        int X=x;
        for (int j=39; j >= 0; j--){
            int ba = (X>>j)&1;
            if (ba==0) continue;
            if (ans[j] == 0){
                tet++;
                ans[j]=X;
                break;
            }
            X ^= ans[j];
        }
    }
    if (x==0 || tet==0) cout << -1;
    else cout << tet;
}