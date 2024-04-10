#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if(a == 1 && b == 1) cout << "0\n";
        else cout << min(min(2, a), b) << "\n";
    }
}