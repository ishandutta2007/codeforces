#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s; s = "$"+s; s+="$";
    int minFront[n+1], maxFront[n+1], minBack[n+2], maxBack[n+2], prefix[n+1];
    int curFront = 0;
    minFront[0] = maxFront[0] = prefix[0] = 0;
    for(int i = 1; i<=n; i++){
        if(s[i] == '-') curFront--;
        else curFront++;
        minFront[i] = min(minFront[i-1], curFront);
        maxFront[i] = max(maxFront[i-1], curFront);
        prefix[i] = curFront;
    }
    minBack[n+1] = maxBack[n+1] = 0;
    for(int i = n; i>=1; i--){
        int delta;
        if(s[i] == '-') delta = -1;
        else delta = 1;
        minBack[i] = min(delta, minBack[i+1]+delta);
        maxBack[i] = max(delta, maxBack[i+1]+delta);
    }
    while(m--){
        int l, r; cin >> l >> r;
        int mi1 = minFront[l-1], ma1 = maxFront[l-1];
        int mi2 = minBack[r+1], ma2 = maxBack[r+1];
        int lb = min(mi1, prefix[l-1]+mi2);
        int rb = max(ma1, prefix[l-1]+ma2);
        cout << rb-lb+1 << endl;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}