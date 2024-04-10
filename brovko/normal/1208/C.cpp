#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, X[1005], Y[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x=i/2;
            int y=j/2;
            int ans=(n/2*x+y)*4;
            if(i%2)
                ans+=2;
            if(j%2)
                ans++;
            X[i]^=ans;
            Y[j]^=ans;
            cout << ans << ' ';
        }
        cout << "\n";
    }

    /*for(int i=0;i<n;i++)
        cout << X[i] << ' ' << Y[i] << "\n";*/
}