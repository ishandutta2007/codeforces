#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
#define MAXN 5005

int a[MAXN],in[MAXN][2],mk[MAXN],dp[MAXN];

int calc(int x,int y)
{
    int res=0;
    vector<int> ns;
    for(int i=x;i<=y;i++)
        if(!mk[a[i]])
        {
            mk[a[i]]=1;
            ns.push_back(a[i]);
            res^=a[i];
        }

    for(auto y : ns)
        mk[y]=0;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
    {
        if(!mk[a[i]])
            mk[a[i]]=i+1;
        in[i][0]=mk[a[i]]-1;
    }

    for(int i=0;i<MAXN;i++)
        mk[i]=0;

    for(int i=n-1;i>=0;i--)
    {
        if(!mk[a[i]])
            mk[a[i]]=i+1;
        in[i][1]=mk[a[i]]-1;
    }

    for(int i=0;i<MAXN;i++)
        mk[i]=0;

    for(int i=0;i<n;i++)
    {
        if(i)
            dp[i]=dp[i-1];
        int mi=i,f=1;
        for(int j=i;j>=mi && f;j--)
        {
            if(in[j][1]>i)
                f=0;
            mi=min(mi,in[j][0]);
        }
        if(f)
            dp[i]=max(dp[i],((!mi) ? 0 : dp[mi-1])+calc(mi,i));
    }

    db(dp[n-1])

    return 0;
}