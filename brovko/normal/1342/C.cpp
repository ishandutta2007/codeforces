#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, a, b, q, l, r, x[200005];

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
        cin >> a >> b >> q;

        x[0]=0;

        int k=2*a*b;

        for(int i=1;i<k;i++)
            if(i%a%b != i%b%a)
                x[i]=x[i-1]+1;
            else x[i]=x[i-1];

        while(q--)
        {
            cin >> l >> r;
            int ans=(r/(a*b)-l/(a*b)) * x[a*b-1];

            l%=a*b;
            r%=a*b;
            if(l==0)
                l++;
            ans+=x[r]-x[l-1];
            cout << ans << ' ';
        }
        cout << "\n";
    }

}