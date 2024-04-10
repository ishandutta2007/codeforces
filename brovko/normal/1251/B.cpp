#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int q, n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--)
    {
        cin >> n;
        int f=0;
        int k=0;
        for(int i=0;i<n;i++)
        {
            cin >> s;
            if(s.size()%2)
                f=1;
            for(auto to:s)
                k+=to-'0';
        }
        if(k%2!=0 && f==0)
            cout << n-1;
        else cout << n;
        cout << "\n";
    }
}