#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int MOD = 1000000007;

int pw[N*N];

void solve(){
    int n, m; cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        cnt += count(s.begin(), s.end(), '#');
    }
    cout << pw[cnt]-(cnt==n*m) << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pw[0] = 1;
    for(int i = 1; i<N*N; i++)
        pw[i] = 2*pw[i-1]%MOD;
    int t; cin >> t;
    while(t--) solve();
}