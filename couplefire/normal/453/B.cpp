#include <bits/stdc++.h>
using namespace std;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int pmask[60];
int n;
int arr[100];
int dp[100][1<<17];
pair<int, int> trans[100][1<<17];
int stuff[100][1<<17];

void trace(int i, int j){
    if(i != 0){
        trace(trans[i][j].first, trans[i][j].second);
    }
    cout << stuff[i][j] << " ";
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 1; i<60; i++){
        for(int j = 0; j<17; j++){
            if(i%primes[j] == 0) pmask[i] ^= (1<<j);
        }
    }
    // cout << pmask[6] << endl;
    memset(dp, 0x3f3f3f3f, sizeof dp);
    for(int i = 0; i<n; i++){
        for(int j = 0, end = (1<<17); j<end; j++){
            for(int k = 1; k<60; k++){
                if((pmask[k]|j) != j) continue;
                if(i == 0){
                    if(abs(arr[i]-k) < dp[i][j]){
                        stuff[i][j] = k;
                        dp[i][j] = abs(arr[i]-k);
                    }
                    continue;
                }
                if(dp[i-1][j^pmask[k]]+abs(arr[i]-k)<dp[i][j]){
                    dp[i][j] = dp[i-1][j^pmask[k]]+abs(arr[i]-k);
                    trans[i][j] = {i-1, j^pmask[k]};
                    stuff[i][j] = k;
                }
            }
        }
    }
    trace(n-1, (1<<17)-1);
}