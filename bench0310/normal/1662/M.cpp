#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int r=0,w=0;
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin >> a >> b;
            r=max(r,a);
            w=max(w,b);
        }
        if(r+w<=n) cout << string(r,'R') << string(n-r,'W') << "\n";
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}