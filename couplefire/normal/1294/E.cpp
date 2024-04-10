#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    int col[m][n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int a; cin >> a;
            col[j][i] = a;
        }
    }
    int ans = 0;
    for(int i = 0; i<m; i++){
        int shift[n];
        int mod = (i+1)%m;
        fill(shift, shift+n, n);
        for(int j = 0; j<n; j++){
            if(col[i][j] % m == mod && col[i][j] >= (i+1) && col[i][j] <= (n-1)*m+i+1) shift[(j-(col[i][j]-i-1)/m+n)%n]--;
        }
        int best = n;
        for(int j = 0; j<n; j++){
            //cout << i << " " << j << " " << shift[j]+j << endl;
            best = min(best, j+shift[j]);
        }
        ans += best;
    }
    cout << ans << endl;
}