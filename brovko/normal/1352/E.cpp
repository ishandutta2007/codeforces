#include <bits/stdc++.h>
//#define int long long
#define y1 ewpojfewopfiwehfew

using namespace std;

int t, n, a[8005], used[8005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        for(int i=0;i<8005;i++)
            used[i]=0;

        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            for(int j=i+1;j<n;j++)
            {
                x+=a[j];
                if(x<8005)
                    used[x]=1;
            }
        }

        int ans=0;
        for(int i=0;i<n;i++)
            if(used[a[i]])
            ans++;
        cout << ans << "\n";
    }
}