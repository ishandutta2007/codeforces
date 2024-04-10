#include <bits/stdc++.h>
//#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int q, l, r, k, pk[1000005][10], g[1000005];

int f(int x)
{
    int ans = 1;

    while(x)
    {
        int c = x%10;
        if(c)
            ans*=c;
        x/=10;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    for(int i=1;i<=1000000;i++)
    {
        if(i<10)
            g[i]=i;
        else g[i]=g[f(i)];

        for(int j=1;j<10;j++)
        {
            if(j==g[i])
                pk[i][j]=pk[i-1][j]+1;
            else pk[i][j]=pk[i-1][j];
        }
    }


    cin >> q;
    while(q--)
    {
        cin >> l >> r >> k;
        cout << pk[r][k]-pk[l-1][k] << "\n";
    }
}