#include <bits/stdc++.h>
#define int long long


using namespace std;

int n, a[100005], ans, used[100005];
map <int, int> m[40];
int f(int x)
{
    if(x%2==0)
        return x+1;
    return x-1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=30;i>=0;i--)
    {
        int k=1;
        for(int j=0;j<n;j++)
        {
            m[i][a[j]/(1ll << i)]++;
        }
        for(int j=0;j<n;j++)
            if(used[j]==0)
            if(m[i][f(a[j]/(1ll << i))]==0)
            k=0;
        for(int j=0;j<n;j++)
            if(used[j]==0)
            if(m[i][f(a[j]/(1ll << i))]!=0 && k==0)
            used[j]=1;
        ans=ans*2+k;
    }
    cout << ans;
}