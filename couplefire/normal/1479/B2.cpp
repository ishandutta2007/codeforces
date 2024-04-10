#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 100005;

int n,a[N];
vector <int> g[N];
int nxt[N];

signed main()
{
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i], g[a[i]].push_back(i);

    for(int i=1;i<=n;i++) nxt[i]=n+1;
    for(int i=1;i<=n;i++) for(int j=1;j<g[i].size();j++) nxt[g[i][j-1]]=g[i][j];

    int val1=0,nxt1=n+1,val2=0,nxt2=n+1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int val=a[i];
        if(val==val1) nxt1=nxt[i];
        else if(val==val2) nxt2=nxt[i];
        else 
        {
            if(nxt1>nxt2) 
            {
                val1=val;
                nxt1=nxt[i];
                ++ans;
            }
            else
            {
                val2=val;
                nxt2=nxt[i];
                ++ans;
            }
        }
    }
    cout<<ans<<endl;
}