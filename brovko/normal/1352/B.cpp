#include <bits/stdc++.h>
#define int long long
#define y1 ewpojfewopfiwehfew

using namespace std;

int t, n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(n<k)
            cout << "NO\n";
        else if(n%2==k%2)
        {
            cout << "YES\n";
            for(int i=0;i<k-1;i++)
                cout << 1 << ' ';
            cout << n-k+1;
            cout << "\n";
        }
        else if(n%2==0 && n>=2*k)
        {
            cout << "YES\n";
            for(int i=0;i<k-1;i++)
                cout << 2 << ' ';
            cout << n-2*k+2;
            cout << "\n";
        }
        else cout << "NO\n";
    }
}