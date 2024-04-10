#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=120000;

int n,a[N],cnt=0;
vector<int> v[101];

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);
        for(int j=60;j>=0;j--)
        {
            if(a[i]&(1ll<<j)) 
            {
                v[j].push_back(i);
                //cout<<j<<" "<<i<<endl;
                break;
            }
        }
    }
    int now=0;
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        int bl=0;
        for(int j=0;j<=60;j++)
        {
            if((now&(1ll<<j))==0&&(int)v[j].size())
            {
                ans.push_back(a[v[j].back()]);
                now^=a[v[j].back()];
                v[j].pop_back(); bl=1; 
                break;
            }
        }
        if(!bl){puts("No"); return 0;}
    }
    puts("Yes");
    for(int i=0;i<(int)ans.size();i++) printf("%lld ",ans[i]);
    return 0;
}