#include <bits/stdc++.h>
using namespace std;
#define MAXN 502
int n;
int arr[MAXN];
int dp[MAXN][MAXN] = {0};
int num[MAXN][MAXN] = {0};

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int len = 1; len<=n; len++){
        for(int start = 0; start+len<=n; start++){
            int i = start; int j = start+len;
            if(j == i+1){
                num[i][j] = arr[i];
                dp[i][j] = 1;
                continue;
            }
            num[i][j] = -1;
            dp[i][j] = len;
            for(int mid = i+1; mid < j; mid++){
                int bruh = dp[i][mid]+dp[mid][j];
                if(bruh == 2 && num[i][mid] > 0 && num[i][mid] == num[mid][j]){
                    dp[i][j] = 1;
                    break;
                }
                dp[i][j] = min(dp[i][j], dp[i][mid]+dp[mid][j]);
            }
            for(int mid = i+1; mid < j; mid++){
                if(num[i][mid] > 0 && num[i][mid] == num[mid][j]){
                    num[i][j] = num[i][mid]+1;
                    break;
                }
            }

        }
    }
    cout << dp[0][n] << endl;
}