#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int arr[n+2];
    for(int i = 1; i<=n; i++) cin >> arr[i];
    int highBit[n+2];
    for(int i = 1; i<=n; i++){
        int cur = 30;
        while((1<<cur) > arr[i]) --cur;
        highBit[i] = cur;
    }
    for(int i = 2; i<=n-1; i++){
        if(highBit[i] == highBit[i-1] && highBit[i] == highBit[i+1]){
            cout << 1 << endl;
            exit(0);
        }
    }
    int leftX[n+2][n+2];
    int rightX[n+2][n+2];
    int ans = INF;
    for(int i = 1; i<=n; i++){
        leftX[i][i] = arr[i];
        rightX[i][i] = arr[i];
        for(int j = i-1; j>=1; j--){
            leftX[i][j] = leftX[i][j+1]^arr[j];
        }
        for(int j = i+1; j<=n; j++){
            rightX[i][j] = rightX[i][j-1]^arr[j];
        }
    }
    for(int i = 1; i<=n-1; i++){
        int a = i, b = i+1;
        for(int x = a; x>=1; x--){
            for(int y = b; y<=n; y++){
                if(leftX[a][x] > rightX[b][y]) ans = min(ans, a-x+y-b);
            }
        }
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}