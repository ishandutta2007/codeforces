#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, s; cin >> n >> s;
        int k = n/2 + 1;
        cout << s/k << "\n";
    }
}