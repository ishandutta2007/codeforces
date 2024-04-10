#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n, m, a[100005], k[100];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        int f=1;
        int s=0;
        int ans=0;
        for(int i=0;i<100;i++)
            k[i]=0;

        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
            cin >> a[i];
            int lg=round(log2(a[i]));
            k[lg]++;
            s+=a[i];
        }
        if(s<n)
            f=0;
        int j=0;
        while(n!=0)
        {
            if(n%2==1)
            {
                if(k[j])
                    k[j]--;
                else
                {
                    int z=j;
                    while(k[z]==0)
                        {
                            z++;
                            ans++;
                        }
                    for(int i=j+1;i<z;i++)
                        k[i]=1;
                    k[z]--;
                }
            }

            k[j+1]+=k[j]/2;
            k[j]%=2;
            n/=2;
            j++;
        }

        if(f==0)
            cout << -1 << endl;
        else cout << ans << endl;
    }
}