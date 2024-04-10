#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int t, n, x, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        k=0;

        for(int i=0;i<n-1;i++)
        {
            int u, v;
            cin >> u >> v;
            if(u==x || v==x)
                k++;
        }

        if(k<=1)
            cout << "Ayush";
        else if((n-3)%2)
            cout << "Ayush";
        else cout << "Ashish";
        cout << "\n";
    }
}