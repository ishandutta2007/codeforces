#include <bits/stdc++.h>
#define int long long

using namespace std;
int v[10][100000];
int where[10][100000];
int ans[100000];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i=0; i < m; i++) for (int j=0; j < n; j++) cin >> v[i][j];
    for (int i=0; i < m; i++) for (int j=0; j < n; j++) v[i][j]--;
    for (int i=0; i < m; i++) for (int j=0; j < n; j++) where[i][v[i][j]] = j;
    for (int i=n-1; i >= 0; i--){
        int nxt = -1;
        if (i < n-1) nxt = v[0][i+1];
        int el = v[0][i];
        for (int j=1; j < m; j++){
            int ind = where[j][el];
            if (ind == n-1){
                nxt = -1;
                break;
            }
            int N = v[j][ind+1];
            if (N != nxt){
                nxt = -1;
                break;
            }
        }
        if (nxt == -1){
            ans[el] = 1;
            continue;
        }
        ans[el] = ans[nxt]+1;
    }
    int res=0;
    for (int i=0;i<n;i++) res += ans[i];
    cout << res;


}