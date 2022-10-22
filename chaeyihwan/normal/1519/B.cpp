#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        if(k == n*m - 1) cout << "YES\n";
        else cout << "NO\n";
    }
}