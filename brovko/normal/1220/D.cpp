#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi

using namespace std;

int n, a[200005], k[105], b[200005], Max;

int f(int x)
{
    int ans=0;
    while(x%2==0)
    {
        ans++;
        x/=2;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        {
            cin >> a[i];
            b[i]=f(a[i]);
            k[b[i]]++;
            Max=max(Max, k[b[i]]);
        }
    for(int i=0;i<105;i++)
        if(k[i]==Max)
    {
        cout << n-k[i] << "\n";
        for(int j=0;j<n;j++)
            if(b[j]!=i)
                cout << a[j] << ' ';
        return 0;
    }
}