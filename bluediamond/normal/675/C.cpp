#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

///const int N=100000+5;

map<ll,vector<int>>p;

int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll s=0LL;
    p[s].push_back(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        s+=x;
        p[s].push_back(i);
    }
    int ans=n;
    for(auto &it:p)
    {
        vector<int>a=it.second;
        if(a.size()<=1) continue;
        int co=0;
        int buc1=a[0];
        for(int i=1;i<a.size();i++)
        {
            int st=a[i-1]+1;
            int dr=a[i];
            co+=(dr-st);
        }
        buc1+=n-a.back();
        if(buc1)
        {
            co+=(buc1-1);
        }
        ans=min(ans,co);

        ///cout<<"\t"<<it.first<<" : "<<buc1<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}
/**


**/