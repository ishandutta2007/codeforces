#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100000+1;
int n;
ll a[N];
vector<ll>who[61];
ll total=0;
ll ans[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        total^=a[i];
        for(int bt=60;bt>=0;bt--)
        {
            if(a[i]&(1LL<<bt))
            {
                who[bt].push_back(i);
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int ind=-1;
        for(int bt=0;bt<=60;bt++)
        {
            if(total&(1LL<<bt) && who[bt].size())
            {
                ind=who[bt][who[bt].size()-1];
                who[bt].pop_back();
                break;
            }
        }
        if(ind==-1)
        {
            cout<<"No\n";
            return 0;
        }
        ans[n+1-i]=a[ind];
        total^=a[ind];
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
/**

**/