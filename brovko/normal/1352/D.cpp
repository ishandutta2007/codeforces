#include <bits/stdc++.h>
#define int long long
#define y1 ewpojfewopfiwehfew

using namespace std;

int t, n, a[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];
        int L=0;
        int R=n-1;
        int k=0;
        int x=0;

        int ans1=0;
        int ans2=0;

        while(R>=L)
        {
            int y=0;
            k++;
            if(k%2)
            {
                while(y<=x && R>=L)
                {
                    y+=a[L];
                    L++;
                }
                ans1+=y;
                x=y;
            }
            else
            {
                while(y<=x && R>=L)
                {
                    y+=a[R];
                    R--;
                }
                ans2+=y;
                x=y;
            }
        }
        cout << k << ' ' << ans1 << ' ' << ans2 << "\n";
    }
}