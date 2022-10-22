#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, a[200005], b[200005], pos[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        pos[a[i]]=1;
    }

    for(int i=0;i<n;i++)
    {
        cin >> b[i];
        pos[b[i]]=i+2;
    }

    int f=1;
    int x=n-b[n-1];
    for(int i=x;i<n;i++)
        if(b[i]!=i-x+1)
            f=0;

    if(b[n-1]==0)
        f=0;

    if(f)
    {
        int y=b[n-1];
        for(int i=y+1;i<=n;i++)
            if(pos[i]-i+y>0)
                f=0;
    }

    if(f)
    {
        cout << n-b[n-1];
        return 0;
    }

    int Max=0;
    for(int i=1;i<=n;i++)
        Max=max(Max, pos[i]-i);
    cout << Max+n;
}