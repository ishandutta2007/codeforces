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
        int n,k;
        cin >> n >> k;
        vector<int> vis(2*n+1,0);
        vector<array<int,2>> edges;
        for(int i=0;i<k;i++)
        {
            int x,y;
            cin >> x >> y;
            vis[x]=vis[y]=1;
            edges.push_back({x,y});
        }
        vector<int> v;
        for(int i=1;i<=2*n;i++) if(vis[i]==0) v.push_back(i);
        for(int i=0;i<n-k;i++) edges.push_back({v[i],v[i+n-k]});
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                auto [a,b]=edges[i];
                auto [c,d]=edges[j];
                a--; b--; c--; d--;
                if(a>b) swap(a,b);
                b=(b-a+2*n)%(2*n);
                c=(c-a+2*n)%(2*n);
                d=(d-a+2*n)%(2*n);
                a=0;
                if(!(b<c&&b<d)&&!(c<b&&d<b)) res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}