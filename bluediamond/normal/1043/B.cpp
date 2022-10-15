#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int v[1005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int last=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v[i]=x-last;
        last=x;
    }
    vector<int>ans;
    for(int l=1;l<=n;l++)
    {
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            if(v[i]!=v[i%l])
            {
                ok=0;
            }
        }
        if(ok)
        {
            ans.push_back(l);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}
/**



**/