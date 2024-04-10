#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> v(m);
    for(int i=0;i<m;i++) cin >> v[i];
    int x;
    cin >> x;
    int res=0;
    for(int y:v) res+=(__builtin_popcount(x^y)<=k);
    cout << res << "\n";
    return 0;
}