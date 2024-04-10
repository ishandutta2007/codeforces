#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin>>n;
        vector<int>v(2*n);
        for(int i=0;i<n;i++)
        {
                cin>>v[i];
                v[n+i]=v[i];
        }
        int cur=0;
        int ans=0;
        for(auto &x:v)
        {
                if(x==1)
                {
                        cur++;
                }
                else
                {
                        cur=0;
                }
                ans=max(ans,cur);
        }
        cout<<ans<<"\n";
        return 0;
}
/**

**/