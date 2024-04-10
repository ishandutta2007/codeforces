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
        vector<int> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int root=0;
        for(int i=1;i<=n;i++) if(v[i].size()>=3) root=i;
        int res=0;
        if(n==1) res=0;
        else if(root==0) res=1;
        else
        {
            function<int(int,int)> dfs=[&](int a,int p)->int
            {
                int b=0,c=0;
                for(int to:v[a])
                {
                    if(to==p) continue;
                    b+=dfs(to,a);
                    c++;
                }
                res+=max(0,b-1);
                return (b==c&&c<=1);
            };
            dfs(root,0);
        }
        cout << res << "\n";
    }
    return 0;
}