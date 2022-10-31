#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    long long n = s.length();
    long long top = n;
    long long ans = 0;
    for(long long i = n-3; i>=0; i--){
        for(long long j = 1; j<=4; j++){
            if(i+2*j >= n) break;
            if(s[i] == s[i+j] && s[i+j] == s[i+2*j]) top = min(top, i+2*j);
        }
        ans += n-top;
    }
    cout << ans << endl;
}