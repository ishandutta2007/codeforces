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
        vector<array<int,2>> v(n);
        for(int i=0;i<n;i++)
        {
            int d;
            cin >> d;
            v[i]={d,i+1};
        }
        ranges::sort(v,greater<>());
        vector<int> vis(n+1,0);
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) p[i]=i;
        vector<int> sz(n+1,1);
        auto find_set=[&](auto &&self,int a)->int
        {
            if(a==p[a]) return a;
            else return p[a]=self(self,p[a]);
        };
        auto merge_sets=[&](int a,int b)
        {
            a=find_set(find_set,a);
            b=find_set(find_set,b);
            if(sz[a]<sz[b]) swap(a,b);
            p[b]=a;
            sz[a]+=sz[b];
        };
        for(auto [d,a]:v)
        {
            if(vis[a]) continue;
            vis[a]=1;
            while(d--)
            {
                cout << "? " << a << endl;
                int b;
                cin >> b;
                merge_sets(a,b);
                if(vis[b]==1) break;
                vis[b]=1;
            }
        }
        cout << "!";
        for(int i=1;i<=n;i++) cout << " " << find_set(find_set,i);
        cout << endl;
    }
    return 0;
}