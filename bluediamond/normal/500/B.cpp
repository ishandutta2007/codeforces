#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300+5;

int n;
int v[N];
bool a[N][N];
vector<int>comp[N];

bool viz[N];

vector<int>g[N];
vector<int>val[N];
int cur=0;

void dfs(int nod)
{
    comp[cur].push_back(nod);
    viz[nod]=1;
    for(auto &nou:g[nod])
    {
        if(viz[nou]==0)
        {
            dfs(nou);
        }
    }
}

int res[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=n;j++)
        {
            if(s[j-1]=='1')
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(viz[i]==0)
        {
            cur++;
            dfs(i);
        }
    }
    for(int i=1;i<=cur;i++)
    {
        for(auto &it:comp[i])
        {
            val[i].push_back(v[it]);
        }
        sort(val[i].begin(),val[i].end());
        sort(comp[i].begin(),comp[i].end());
        for(int j=0;j<comp[i].size();j++)
        {
            res[comp[i][j]]=val[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
    for(int i=1;i<=cur;i++)
    {
      ///  sort(comp[i].begin(),comp[i].end());
        for(auto &x:comp[i]) cout<<x<<" ";
        cout<<"\n";
    }

    return 0;
}
/**

**/