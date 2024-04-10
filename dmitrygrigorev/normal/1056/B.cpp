#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int ost[m], rost[m];
    for (int i=0;i<m;i++) ost[i] = 0;
    for (int i=0; i < m; i++){
        int ch = n-i, zn = m;
        if (ch >= 0){
            ost[i] = ch/zn + 1;
        }
    }
    if (ost[0] > 0) ost[0]--;
    for (int i=0;i<m;i++) rost[i] = 0;
    for (int i=0;i<m;i++) rost[(i*i)%m] += ost[i];
    int ans = 0;
    for (int i=0;i<m;i++){
        for (int j=0; j < m; j++){
            if ((i+j)%m==0) ans += rost[i]*rost[j];
        }
    }
    cout << ans;

}