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
        int root=0;
        for(int i=1;i<=n;i++)
        {
            int p;
            cin >> p;
            if(p==i) root=i;
            else v[p].push_back(i);
        }
        vector<int> p(n+1,-1);
        p[root]=0;
        vector<int> u(n+1,0);
        vector<int> d(n+1,0);
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            if(p[a]!=-1)
            {
                u[a]=i-d[p[a]];
                d[a]=i;
                for(int to:v[a]) p[to]=a;
            }
            else ok=0;
        }
        if(ok) for(int i=1;i<=n;i++) cout << u[i] << " \n"[i==n];
        else cout << "-1\n";
    }
    return 0;
}