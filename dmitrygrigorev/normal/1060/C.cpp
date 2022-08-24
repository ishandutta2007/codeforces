#include <bits/stdc++.h>
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), ms(m);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int j=0; j < m; j++) cin >> b[j];
    int x;
    cin >> x;
    fill(ms.begin(), ms.end(), 1e9);
    for (int i=0; i < m; i++){
        int S = 0;
        for (int j=i; j < m; j++){
            S += b[j];
            ms[j-i] = min(ms[j-i], S);
        }
    }
    //for (int i=0;i<m;i++) cout << ms[i] << endl;
    int ans = 0;
    for (int i=0; i < n; i++){
        int S = 0;
        int u = m-1;
        for (int j=i; j < n; j++){
            S += a[j];
            int need = x/S;
            while (u >= 0 && ms[u] > need) u--;
            if (u<0) break;
            ans = max(ans, (j-i+1)*(u+1));
            //cout << i << " " << j << " " << need << endl;
        }
    }
    cout << ans;

}