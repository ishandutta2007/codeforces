#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    a[0]=a[1]-1;
    int res=0;
    if(k==n) res=a[n];
    else if(a[k]!=a[k+1]) res=a[k];
    if(res>0) cout << res << "\n";
    else cout << "-1\n";
    return 0;
}