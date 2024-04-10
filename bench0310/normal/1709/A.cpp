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
        int x;
        cin >> x;
        array<int,4> vis={0,0,0,0};
        array<int,4> a;
        for(int i=1;i<=3;i++) cin >> a[i];
        vis[x]=1;
        while(a[x]!=0)
        {
            x=a[x];
            vis[x]=1;
        }
        if(vis[1]+vis[2]+vis[3]==3) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}