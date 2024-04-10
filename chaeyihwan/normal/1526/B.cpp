#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int x; cin >> x;
        int d = x%11;
        if(x >= d * 111) cout << "YES\n";
        else cout << "NO\n";
    }
}