#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

bool dp[N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    dp[0] = 1;
    for(int i = 1; i<N; i++){
        if(i >= 11) dp[i] |= dp[i-11];
        if(i >= 111) dp[i] |= dp[i-111];
    }
    while(t--){
        int x; cin >> x;
        if(x >= N) cout << "YES" << endl;
        else cout << (dp[x]?"YES":"NO") << endl;
    }
}