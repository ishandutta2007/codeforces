#include <bits/stdc++.h>
using namespace std;

int n, q;
string s;
int dp[1<<19];

void trans(int i){
    if(s[i] == '?') dp[i] = dp[i*2]+dp[i*2+1];
    else if(s[i] == '1') dp[i] = dp[i*2];
    else dp[i] = dp[i*2+1];
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cin >> n >> s;
    n = (1<<n);
    for(int i = 0; i<((n-1)/2); i++)
        swap(s[i], s[n-2-i]);
    s = "$"+s;
    for(int i = 2*n-1; i>=n; i--) dp[i] = 1;
    for(int i = n-1; i>=1; i--)
        trans(i);
    cin >> q;
    while(q--){
        int p; char c;
        cin >> p >> c; p = n-p;
        s[p] = c;
        while(p>0) trans(p), p /= 2;
        cout << dp[1] << '\n'; 
    }
}