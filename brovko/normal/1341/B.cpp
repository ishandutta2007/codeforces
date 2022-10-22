#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, k, a[200005], p[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i=0;i<n;i++)
            cin >> a[i];

        p[0]=0;
        p[n-1]=0;

        for(int i=1;i<n-1;i++)
            if(a[i]>a[i-1] && a[i]>a[i+1])
                p[i]=1;
            else p[i]=0;

        int s=0;
        int Max=-1;
        int ind=0;

        for(int i=1;i<k-1;i++)
            s+=p[i];
        if(s>Max)
            {
                Max=s;
                ind=1;
            }

        for(int i=k;i<n;i++)
        {
            s+=p[i-1]-p[i-k+1];
            if(s>Max)
            {
                Max=s;
                ind=i-k+2;
            }
        }

        cout << Max+1 << ' ' << ind << "\n";
    }
}