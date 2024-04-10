#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    if(min(n, m)>=4){
        cout << -1 << endl;
        return 0;
    }
    if(min(n,m) == 1){
        cout << 0 << endl;
        return 0;
    }
    if(n == 2){
        int dp[m+1][2][2];
        string s1, s2; cin >> s1 >> s2;
        int arr[m+1], brr[m+1];
        for(int i = 0; i<m; i++) arr[i+1] = s1[i]-'0';
        for(int i = 0; i<m; i++) brr[i+1] = s2[i]-'0';
        for(int i = 0; i<2; i++) for(int j = 0; j<2; j++) dp[0][i][j] = 0;
        for(int i = 1; i<=m; i++){
            for(int a = 0; a<2; a++){
                for(int b = 0; b<2; b++){
                    dp[i][a][b] = INF;
                    for(int aa = 0; aa<2; aa++){
                        for(int bb = 0; bb<2; bb++){
                            if((aa+bb+a+b)%2==0) continue;
                            dp[i][a][b] = min(dp[i][a][b], dp[i-1][aa][bb]+(aa^arr[i])+(bb^brr[i]));
                        }
                    }
                }
            }
        }
        int ans = INF;
        for(int a = 0; a<2; a++){
            for(int b = 0; b<2; b++){
                ans = min(ans, dp[m-1][a][b]+(a^arr[m])+(b^brr[m]));
            }
        }
        cout << ans << endl;
    }
    if(n == 3){
        int dp[m+1][2][2][2];
        string s1, s2, s3; cin >> s1 >> s2 >> s3;
        int arr[m+1], brr[m+1], crr[m+1];
        for(int i = 0; i<m; i++) arr[i+1] = s1[i]-'0';
        for(int i = 0; i<m; i++) brr[i+1] = s2[i]-'0';
        for(int i = 0; i<m; i++) crr[i+1] = s3[i]-'0';
        for(int a = 0; a<2; a++) for(int b = 0; b<2; b++) for(int c = 0; c<2; c++) dp[0][a][b][c] = 0;
        for(int i = 1; i<=m; i++){
            for(int a = 0; a<2; a++){
                for(int b = 0; b < 2; b++){
                    for(int c = 0; c<2; c++){
                        dp[i][a][b][c] = INF;
                        for(int aa = 0; aa<2; aa++){
                            for(int bb = 0; bb<2; bb++){
                                for(int cc = 0; cc<2; cc++){
                                    if((aa+bb+a+b)%2 == 0 || (bb+cc+b+c)%2 == 0) continue;
                                    dp[i][a][b][c] = min(dp[i][a][b][c], dp[i-1][aa][bb][cc]+(aa^arr[i])+(bb^brr[i])+(cc^crr[i]));
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = INF;
        for(int a = 0; a<2; a++){
            for(int b = 0; b<2; b++){
                for(int c = 0; c<2; c++){
                    ans = min(ans, dp[m-1][a][b][c]+(a^arr[m])+(b^brr[m])+(c^crr[m]));
                }
            }
        }
        cout << ans << endl;
    }
}