#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int Min=11;
        int Max=-1;
        cin >> n >> k;
        for(int i=2;(i<=k && Min!=0);i++)
        {
            Min=11;
            Max=-1;
            int y=1;
            for(int i=0;y<=n;i++)
            {
                Min=min(Min, n/y%10);
                Max=max(Max, n/y%10);
                if(y==1e18)
                    y=2e18;
                else
                y*=10;
            }
            n+=Min*Max;
        }
        cout << n << "\n";
    }
}