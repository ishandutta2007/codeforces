#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
#define MAXA 2005

int n;
bitset<MAXN*MAXA> dp[MAXN];
int arr[MAXN];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> arr[i];
    int minpw = MAXA;
    for(int i = 1; i<=n; i++){
        int cur = arr[i];
        int pw = 0;
        while(cur%2 == 0) pw++, cur /= 2;
        minpw = min(minpw, pw);
    }
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<minpw; j++) arr[i] /= 2;
    }
    int tot = 0;
    for(int i = 1; i<=n; i++) tot += arr[i];
    if(tot%2){
        cout << 0 << endl;
        exit(0);
    }
    for(int i = 0; i<=n; i++) dp[i].reset();
    dp[0].set(0);
    for(int i = 1; i<=n; i++){
        dp[i] = (dp[i-1]|(dp[i-1] << arr[i]));
    }
    if(dp[n].test(tot/2)){
        cout << 1 << endl;
        for(int i = 1; i<=n; i++){
            if(arr[i]%2){
                cout << i << endl;
                exit(0);
            }
        }
    }
    else{
        cout << 0 << endl;
        exit(0);
    }
}