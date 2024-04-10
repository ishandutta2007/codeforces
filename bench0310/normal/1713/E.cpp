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
        vector<int> x(n+1,0);
        vector<int> p(n+1,0);
        vector<int> sz(n+1,1);
        for(int i=1;i<=n;i++) p[i]=i;
        function<int(int)> find_set=[&](int a)->int
        {
            if(a==p[a]) return a;
            else
            {
                int tmp=find_set(p[a]);
                x[a]^=x[p[a]];
                return (p[a]=tmp);
            }
        };
        auto merge_sets=[&](int a,int b,int c)->bool
        {
            int pa=find_set(a);
            int pb=find_set(b);
            if(pa==pb) return ((x[a]^x[b])==c);
            if(sz[pa]<sz[pb])
            {
                swap(a,b);
                swap(pa,pb);
            }
            if((x[a]^x[b])!=c) x[pb]^=1;
            p[pb]=pa;
            sz[pa]+=sz[pb];
            return 1;
        };
        vector a(n+1,vector(n+1,int(0)));
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> a[i][j];
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i][j]==a[j][i]) continue;
                int c=(a[i][j]>a[j][i]);
                if(merge_sets(i,j,c)==c) swap(a[i][j],a[j][i]);
            }
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout << a[i][j] << " \n"[j==n];
    }
    return 0;
}