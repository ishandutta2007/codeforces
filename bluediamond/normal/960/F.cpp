#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;

int n,m;

set<int>s[N];
map<int,int>val[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        s[i].insert(-1);
    }
    while(m--)
    {
        int a,b,x;
        cin>>a>>b>>x;
        auto it=s[a].lower_bound(x);
        it--;
        int y=val[a][*it]+1;
        it=s[b].lower_bound(x+1);
        it--;
        if(val[b][*it]>=y) continue;
        while(1)
        {
            it=s[b].lower_bound(x);
            if(it==s[b].end()) break;
            if(val[b][*it]>y) break;
            s[b].erase(it);
        }
        s[b].insert(x);
        val[b][x]=y;
    ///    cout<<dp(b,x)<<" "<<y<<"\n";
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        auto it=s[i].end();
        it--;
        ans=max(ans,val[i][*it]);
    }
    cout<<ans<<"\n";
    return 0;
}
/**

2 1
1 2 0

**/