#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int inf=1000000000;
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    string b;
    for(int i=1;i<=n;i++) cin >> a[i];
    cin >> b;
    b="$"+b;
    int l=-inf;
    int r=inf;
    for(int i=5;i<=n;i++)
    {
        if(b[i]!=b[i-1])
        {
            if(b[i]=='1') l=max(l,max({a[i-4],a[i-3],a[i-2],a[i-1],a[i]})+1);
            else r=min(r,min({a[i-4],a[i-3],a[i-2],a[i-1],a[i]})-1);
        }
    }
    cout << l << " " << r << "\n";
    return 0;
}