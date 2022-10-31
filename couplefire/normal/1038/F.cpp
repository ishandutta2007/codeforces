#include <bits/stdc++.h>
using namespace std;
#define MAXN 45

int n; string s;
vector<int> arr;
int trans[MAXN][2];
int pi[MAXN];
long long dp[MAXN][MAXN][MAXN];
long long num[MAXN];
int tmp[MAXN];
pair<int, int> badbad[MAXN];

void precalc(){
    if(arr[0] == 1) trans[0][1] = 1;
    else trans[0][0] = 1;
    for(int i = 1; i<arr.size(); i++){
        int j = pi[i-1];
        while(j > 0 && arr[i] != arr[j]) j = pi[j-1];
        if(arr[i] == arr[j]) j++;
        pi[i] = j;
    }
    for(int i = 1; i<=arr.size(); i++){
        for(int j = 0; j<2; j++){
            if(i != arr.size() && arr[i] == j){
                trans[i][j] = i+1;
                continue;
            }
            int k = pi[i-1];
            while(k > 0 && arr[k] != j) k = pi[k-1];
            if(arr[k] == j) k++;
            trans[i][j] = k;
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i<s.length(); i++) arr.push_back(s[i]-'0');
    precalc();
    // cout << trans[4][1-arr[4]] << endl;
    dp[0][0][0] = 1;
    int best = 0;
    for(int i = 1; i<=arr.size(); i++){
        bool lol = true;
        for(int j = 0; j<i; j++) lol &= (arr[j] == arr[arr.size()-i+j]);
        if(lol) best = i;
        dp[i][i][best] = 1;
        tmp[i] = best;
        int cur = 0;
        for(int j = 1; j<i; j++){
            bool lol = true;
            for(int m = 0; m<j; m++) lol &= (arr[arr.size()-1-m] == arr[arr.size()-i+j-1-m]);
            if(lol) cur = j;
        }
        badbad[i] = {cur, best};
    }
    for(int i = 0; i<n; i++){ // cur length
        for(int a = 0; a<=i; a++){ // // prfix length
            for(int b = 0; b<=i; b++){ // suffix length
                long long cur = dp[i][a][b];
                if(a == arr.size() || b == arr.size()){
                    dp[i][a][b] = 0;
                    continue;
                }
                if(cur == 0) continue;
                if(a == badbad[i].first && b == badbad[i].second && i != 0 && i <= arr.size()){
                    cur--;
                    dp[i][a][b]--;
                }
                dp[i+1][a][trans[b][0]] += cur;
                dp[i+1][a][trans[b][1]] += cur;
            }
        }
    }
    // cout << dp[1][0][0] << endl;
    long long ans = 0;
    for(int a = 0; a<arr.size(); a++){
        for(int b = 0; b<arr.size(); b++){
            bool good = false;
            if(dp[n][b][a] == 0) continue;
            for(int k = 1; k<arr.size(); k++){
                if(k > a) continue;
                if(arr.size()-k > b) continue;
                bool lol = true;
                for(int m = 0; m<k; m++) lol &= (arr[m] == arr[a-k+m]);
                for(int m = 0; m<arr.size()-k; m++) lol &= (arr[arr.size()-1-m] == arr[arr.size()-b+(arr.size()-k)-1-m]);
                if(lol) good = true;
                if(good) break;
            }
            if(good){
                ans += dp[n][b][a];
                // cout << b << " " << a << endl;
            }
        }
    }
    for(int i = 1; i<=n; i++){
        num[i] += num[i-1]*2ll;
        for(int a = 0; a<s.length(); a++) num[i] += dp[i-1][a][s.length()-1];
    }
    // cout << ans << endl;
    ans += num[n];
    cout << ans << endl;
}