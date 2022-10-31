#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    long long n = (s.length()+1)/2;
    long long dp[n][n];
    long long frontdp[n];
    long long backdp[n];
    long long cur = 0;
    long long pro = 1;
    for(long long i = 0; i<s.length(); i++){
        if(s[i]-'0' > 9 || s[i]-'0' < 0) continue;
        pro *= s[i]-'0';
        if(i == s.length()-1 || s[i+1] == '+'){
            cur += pro;
            pro = 1;
            frontdp[i/2] = cur;
        }
    }
    cur = 0;
    pro = 1;
    reverse(s.begin(), s.end());
    for(long long i = 0; i<s.length(); i++){
        if(s[i]-'0' > 9 || s[i]-'0' < 0) continue;
        pro *= s[i]-'0';
        if(i == s.length()-1 || s[i+1] == '+'){
            cur += pro;
            pro = 1;
            backdp[(s.length()-i-1)/2] = cur;
        }
    }
    reverse(s.begin(), s.end());
    long long ans = 0;
    for(long long len = 0; len<n; len++){
        for(long long i = 0; i+len<n; i++){
            long long j = i+len;
            long long pos = -1;
            for(long long k = i; k<j; k++){
                if(s[k*2+1] == '+'){
                    pos = k;
                    break;
                }
            }
            if(pos == -1){
                long long pro = 1;
                for(long long k = i; k<=j; k++){
                    pro *= s[2*k]-'0';
                }
                dp[i][j] = pro;
            }
            else{
                dp[i][j] = dp[i][pos]+dp[pos+1][j];
            }
            long long pro1 = 1;
            long long pro2 = 1;
            long long curdp = dp[i][j];
            long long curans = 0;
            for(long long k = i-1; k>= 0; k--){
                if(s[2*k+1] == '+'){
                    curans += frontdp[k];
                    break;
                }
                pro1 *= s[2*k]-'0';
            }
            curdp *= pro1;
            for(long long k = j+1; k<n; k++){
                if(s[2*k-1] == '+'){
                    curans += backdp[k];
                    break;
                }
                pro2 *= s[2*k]-'0';
            }
            curdp *= pro2;
            ans = max(ans, curdp+curans);
        }
    }
    cout << ans << endl;
}