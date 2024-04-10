#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n>1) cout << n << " " << n+1 << " " << n*(n+1) << "\n";
    else cout << "-1\n";
    return 0;
}