#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    string s;
    cin >> s;
    string s1 = s.substr(0,n);
    string s2 = s.substr(n,string::npos);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string best = "";
    long long bestsum = -1;
    pair<long long, string> dp[n+1];
    fill(dp, dp+n+1, make_pair(-1, ""));
    for(int mask = 0; mask<(1<<n); mask++){
        string ss = "";
        long long val1 = 0, val2 = 0;
        for(int i = n-1; i>=0; i--){
            if(mask&(1<<i)) ss += "M", val1 = 10*val1+s2[i]-'0';
            else ss += "H", val2 = 10*val2+s2[i]-'0';
        }
        if(val1+val2 > dp[__builtin_popcount(mask)].first){
            dp[__builtin_popcount(mask)] = {val1+val2, ss};
        }
    }
    for(int mask = 0; mask<(1<<n); mask++){
        string ss = "";
        long long val1 = 0, val2 = 0;
        for(int i = n-1; i>=0; i--){
            if(mask&(1<<i)) ss += "M", val1 = 10*val1+s1[i]-'0';
            else ss += "H", val2 = 10*val2+s1[i]-'0';
        }
        val1 = val1*pow(10, n-__builtin_popcount(mask));
        val2 = val2*pow(10, __builtin_popcount(mask));
        if(val1+val2+dp[n-__builtin_popcount(mask)].first > bestsum){
            bestsum = val1+val2+dp[n-__builtin_popcount(mask)].first;
            best = ss + dp[n-__builtin_popcount(mask)].second;
        }
    }
    cout << best << endl;
}