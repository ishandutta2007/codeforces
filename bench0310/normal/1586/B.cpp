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
        vector<bool> v(n+1,0);
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            v[b]=1;
        }
        int r=0;
        for(int i=1;i<=n;i++) if(!v[i]) r=i;
        for(int i=1;i<=n;i++) if(i!=r) cout << i << " " << r << "\n";
    }
    return 0;
}