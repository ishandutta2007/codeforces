#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[2000][2000], rev[2000][2000];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    cin >> n;
    if (n==1){cout << 1 << endl;
    return 0;}
    vector<int> v(n);
    for (int i=0; i < n; i++){
        cin >> v[i];
    }
    int po[n+1], pt[n+1];
    po[0]=0, pt[0]=0;
    for (int i=0; i < n; i++){
        po[i+1] = po[i] + (v[i] == 1);
        pt[i+1] = pt[i] + (v[i] == 2);
    }
    for (int i=0; i < n; i++){
        int num = (v[i] == 1);
        arr[i][i] = 1;
        for (int j=i+1; j < n; j++){
            if (v[j] == 2) arr[i][j] = arr[i][j-1]+1;
            else{
                num++;
                arr[i][j] = max(arr[i][j-1], num);
            }
        }
    }
    for (int i=0; i < n; i++){
        int num = (v[i] == 1);
        rev[i][i] = 1;
        for (int j=i-1; j >= 0; j--){
            if (v[j] == 2) rev[j][i] = rev[j+1][i]+1;
            else{
                num++;
                rev[j][i] = max(rev[j+1][i], num);
            }
        }
    }
    int ans = 0;
    for (int i=0; i < n; i++){
        for (int j=i; j < n; j++){
            if (j < n-1) ans = max(ans, po[j+1] + arr[j+1][n-1]);
            ans = max(ans, po[i] + rev[i][j] + pt[n] - pt[j+1]);
            if (i!=0) ans = max(ans, arr[0][i-1] + pt[n] - pt[i]);
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
}