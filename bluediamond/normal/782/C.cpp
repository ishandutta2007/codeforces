#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)200000+5;
int n;
vector<int>v[N];
bool viz[N];
int ans=0,sol[N];

void dfs(int dad,int nod)
{
    viz[nod]=1;
    int cnt=1;
    for(auto nou:v[nod])
    {
        if(viz[nou]) continue;
        if(cnt==sol[dad]) cnt++;
        if(cnt==sol[nod]) cnt++;
        if(cnt==sol[dad]) cnt++;
        sol[nou]=cnt++;
        dfs(nod,nou);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        ans=max(ans,(int)v[x].size());
        ans=max(ans,(int)v[y].size());
    }
    cout<<ans+1<<"\n";
    sol[1]=1;
    int cnt=2;
    viz[1]=1;
    for(auto nou:v[1])
    {
        sol[nou]=cnt++;
        dfs(1,nou);
    }
    for(int i=1;i<=n;i++)
        cout<<sol[i]<<" ";
    cout<<"\n";
    return 0;
}
/**

+++++++++++++++++++++++++++++++++++++++
**/