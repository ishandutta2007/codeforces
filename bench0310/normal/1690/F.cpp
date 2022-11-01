#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s="$"+s;
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) cin >> p[i];
        vector<bool> vis(n+1,0);
        ll res=1;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            int a=i;
            string t;
            while(!vis[a])
            {
                t+=s[a];
                vis[a]=1;
                a=p[a];
            }
            string ini=t;
            for(int j=1;;j++)
            {
                rotate(t.begin(),t.begin()+1,t.end());
                if(t==ini)
                {
                    res=lcm(res,j);
                    break;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}