#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;

int n,k,cnt[N];
vector<int>v[N];
int sz[N];
bool lft[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int a,b; cin>>a>>b;
        v[a].push_back(b); sz[a]++;
        v[b].push_back(a); sz[b]++;
    }
    for(int i=1;i<=n;i++) lft[i]=1;
    for(int t=1;t<=k;t++)
    {
        vector<int>e;
        for(int i=1;i<=n;i++)
        {
            if(sz[i]==1)
            {
                e.push_back(i);
                lft[i]=0;
            }
        }
        if(e.empty())
        {
            cout<<"No\n";
            return 0;
        }
        for(int i=1;i<=n;i++)
        {
            cnt[i]=0;
        }
        for(auto nod:e)
        {
            sz[nod]=-1;
            for(auto nou:v[nod])
            {
                sz[nou]--;
                cnt[nou]++;
            }
        }
     /**   for(auto x:e) cout<<x<<" ";
        cout<<"\n"; **/
        for(int i=1;i<=n;i++)
        {
            if(lft[i] && cnt[i]>0 && cnt[i]<3)
            {
            ///    cout<<i<<"\n";
                cout<<"No\n";
                return 0;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(lft[i])
        {
            cnt++;
        }
    }
    if(cnt==1)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }

    return 0;
}
/**


**/