#include <bits/stdc++.h>
#define int long long
#define y1 ewpojfewopfiwehfew

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n<4)
            cout << "-1\n";
        else
        {
            int x;
            if(n%2)
                x=n;
            else x=n-1;
            for(int i=x;i>=1;i-=2)
                cout << i << ' ';
            cout << "4 2 ";
            for(int i=6;i<=n;i+=2)
                cout << i << ' ';
            cout << "\n";
        }
    }
}