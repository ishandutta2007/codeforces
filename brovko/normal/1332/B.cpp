#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, a[1005], c[1005];

int32_t main()
{
    int b[11]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            int f=1;
            int x=0;
            while(f)
            {
                if(a[i]%b[x]==0)
                {
                    c[i]=x+1;
                    f=0;
                }
                x++;
            }
        }

        int x=1;
        int d[15];
        for(int i=0;i<15;i++)
            d[i]=-1;
        for(int i=0;i<n;i++)
            if(d[c[i]]==-1)
        {
            d[c[i]]=x;
            x++;
        }

        cout << x-1 << endl;
        for(int i=0;i<n;i++)
            cout << d[c[i]] << ' ';
        cout << endl;
    }
}