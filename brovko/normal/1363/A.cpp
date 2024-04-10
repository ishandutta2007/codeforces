#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int t, n, x, a[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        int kc=0;
        int knc=0;

        cin >> n >> x;
        for(int i=0;i<n;i++)
            {
                cin >> a[i];
                if(a[i]%2)
                    knc++;
                else kc++;
            }

        if(kc>0 && knc>0 && n>x)
            cout << "Yes";
        else if(n==x && knc%2!=0)
            cout << "Yes";
        else if(x%2!=0 && knc!=0 && n>x)
            cout << "Yes";
        else cout << "No";
        cout << "\n";
    }
}