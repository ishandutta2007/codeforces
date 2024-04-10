#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

int dp[MAXN][26] = {{0}};
int precalc[MAXN][26] = {{0}};
int frontlongest[MAXN][26] = {{0}};
int backlongest[MAXN][26] = {{0}};
string arr[MAXN];
int n;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<26; j++){
            int cur = 0;
            for(auto c : arr[i]){
                if(c-'a' == j) precalc[i][j] = max(precalc[i][j],  ++cur);
                else cur = 0;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<26; j++){
            int cur = 0;
            for(int x = 0; x<arr[i].length(); x++){
                if(arr[i][x]-'a' == j) cur++;
                else break;
            }
            frontlongest[i][j] = cur;
            cur = 0;
            for(int x = arr[i].length()-1; x>=0; x--){
                if(arr[i][x]-'a' == j) cur++;
                else break;
            }
            backlongest[i][j] = cur;
        }
    }
    for(int i = 0; i<26; i++) dp[0][i] = precalc[0][i];
    for(int i = 1; i<n; i++){
        for(int j = 0; j<26; j++){
            if(!dp[i-1][j]){
                dp[i][j] = precalc[i][j];
                continue;
            }
            if(precalc[i][j] != arr[i].length()){
                dp[i][j] = max(precalc[i][j], frontlongest[i][j]+backlongest[i][j]+1);
                continue;
            }
            dp[i][j] = arr[i].length()*(dp[i-1][j]+1)+dp[i-1][j];
        }
    }
    int ans = 0;
    for(int i = 0; i<26; i++) ans = max(ans, dp[n-1][i]);
    cout << ans << endl;
}