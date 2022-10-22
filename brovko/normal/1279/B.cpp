#include <bits/stdc++.h>
#define int long long

using namespace std;
int t, n, s, a[100005], k, Max, ind;

int32_t main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        for(int i=0;i<n;i++)
            cin >> a[i];
        int s1=0;
        for(int i=0;i<n;i++)
            s1+=a[i];
        if(s>=s1)
            cout << 0 << endl;
        else
        {
            k=0;
            Max=0;
            ind=0;
            for(int i=0;i<n;i++)
            {
                if(k+a[i]<=s)
                {
                    k+=a[i];
                    if(a[i]>Max)
                    {
                        Max=a[i];
                        ind=i+1;
                    }
                }
                else
                {
                    if(a[i]>Max)
                        ind=i+1;
                    i=n;
                }
            }
            cout << ind << endl;
        }

    }
    return 0;
}