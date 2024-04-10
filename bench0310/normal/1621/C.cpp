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
        int n;
        cin >> n;
        auto q=[&](int i)->int
        {
            cout << "? " << i << endl;
            int p;
            cin >> p;
            if(p==0) exit(0);
            return p;
        };
        vector<bool> vis(n+1,0);
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            int a=q(i);
            vector<int> v;
            while(!vis[a])
            {
                v.push_back(a);
                vis[a]=1;
                a=q(i);
            }
            int sz=v.size();
            for(int j=0;j<sz;j++) p[v[j]]=v[(j+1)%sz];
        }
        cout << "!";
        for(int i=1;i<=n;i++) cout << " " << p[i];
        cout << endl;
    }
    return 0;
}