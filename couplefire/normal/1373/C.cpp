#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.length();
        int f[n+1];
        fill(f, f+n+1, INF);
        int cur = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '+') cur--;
            if(s[i] == '-') cur++;
            if(cur >= 1) f[cur] = min(f[cur], i);
        }
        long long ans = 0;
        for(int i = 1; i<=n; i++){
            if(f[i] == INF) break;
            ans += f[i]+1;
        }
        cout << ans+n << endl;
    }
}