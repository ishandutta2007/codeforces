#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> pos(n+1,{0,0});
    for(int i=1;i<=n;i++) for(int j=0;j<2;j++) cin >> pos[i][j];
    vector<int> res(30,0);
    for(int b=0;b<30;b++)
    {
        int m=(1<<b);
        vector<array<int,2>> e;
        auto add=[&](int l,int r)
        {
            e.push_back({l,1});
            e.push_back({r+1,-1});
        };
        for(int i=1;i<=n;i++)
        {
            int sz=pos[i][1]-pos[i][0]+1;
            if(sz>=m) add(0,m-1);
            else
            {
                int l=(pos[i][0]%m);
                int r=(pos[i][1]%m);
                if(l<=r) add(l,r);
                else
                {
                    add(l,m-1);
                    add(0,r);
                }
            }
        }
        ranges::sort(e);
        int c=0;
        for(auto [p,d]:e)
        {
            c+=d;
            res[b]=max(res[b],c);
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int w;
        cin >> w;
        int b=0;
        while(((w>>b)&1)==0) b++;
        cout << res[b] << "\n";
    }
    return 0;
}