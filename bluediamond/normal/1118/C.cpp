#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=400+7;

int n;
int v[N];

const int L=1000+7;

int f[L];

bool viz[27][27];
int res[27][27];

struct kek
{
        int r;
        int c;
        int cnt;
};

bool cmp(kek a,kek b)
{
        return a.cnt>b.cnt;
}

int32_t main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n*n;i++)
        {
                cin>>v[i];
                f[v[i]]++;
        }
        vector<kek>ans;
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=n;j++)
                {
                        if(viz[i][j]) continue;
                        set<pair<int,int>>s;
                        s.insert({i,j});
                        s.insert({i,n+1-j});
                        s.insert({n+1-i,j});
                        s.insert({n+1-i,n+1-j});
                        ans.push_back({i,j,s.size()});
                }
        }
        sort(ans.begin(),ans.end(),cmp);
        for(auto &it:ans)
        {
                        int i=it.r;
                        int j=it.c;
                        if(viz[i][j]) continue;
                        set<pair<int,int>>s;
                        s.insert({i,j});
                        s.insert({i,n+1-j});
                        s.insert({n+1-i,j});
                        s.insert({n+1-i,n+1-j});
                        bool g=0;
                        for(int a=1;a<L;a++)
                        {
                                if(f[a]>=s.size())
                                {
                                        g=1;
                                        f[a]-=s.size();
                                        for(auto &it:s)
                                        {
                                                int r=it.first;
                                                int c=it.second;
                                                viz[r][c]=1;
                                                res[r][c]=a;
                                        }
                                        break;
                                }
                        }
                        if(g==0)
                        {
                                cout<<"NO\n";
                                return 0;
                        }
        }
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=n;j++)
                {
                        cout<<res[i][j]<<" ";
                }
                cout<<"\n";
        }
        return 0;
}
/**



**/