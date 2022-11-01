#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    vector<int> a(x+1,0);
    for(int i=1;i<=n;i++)
    {
        int b;
        cin >> b;
        a[b]++;
    }
    bool ok=1;
    for(int i=1;i<x;i++)
    {
        a[i+1]+=(a[i]/(i+1));
        ok&=((a[i]%(i+1))==0);
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}