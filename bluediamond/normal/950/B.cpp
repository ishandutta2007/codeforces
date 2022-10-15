#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100000;

int n,v1[N+5];
int m,v2[N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v1[i];
    for(int i=1;i<=m;i++)
        cin>>v2[i];
    int ans=0;
    int sum=0;
    int p=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        sum+=v1[i];
        while(p<m && sum2<sum)
        {
            p++;
            sum2+=v2[p];
        }
        if(sum==sum2)
        {
            ans++;
            sum=sum2=0;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/**
**/