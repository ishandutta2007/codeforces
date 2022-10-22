#include <bits/stdc++.h>
//#define int long long
#define y1 ewpojfewopfiwehfew

using namespace std;

int t, n0, n1, n2;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n0 >> n1 >> n2;
        if(n0==0 && n1==0)
        {
            for(int i=0;i<n2+1;i++)
                cout << 1;
            cout << "\n";
        }
        else if(n1==0 && n2==0)
        {
            for(int i=0;i<n0+1;i++)
                cout << 0;
            cout << "\n";
        }
        else
        {
            for(int i=0;i<n0+1;i++)
                cout << 0;
            for(int i=0;i<n2+1;i++)
                cout << 1;
            for(int i=0;i<n1-1;i++)
                cout << i%2;
            cout << "\n";
        }
    }
}