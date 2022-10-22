#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n;

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
        vector <int> v;
        cin >> n;
        if(n==2)
            cout << "1\n0\n";
        else if(n==3)
            cout << "1\n1\n";
        else
        {
            int x=1;
            while(n>4*x+3)
                {
                    v.push_back(x);
                    x=x*2+1;
                }
            v.push_back(x);
            v.push_back(max(x+(n-x+2)/3, 2*x-x/2));
            v.push_back(n);

            vector <int> u;
            u.push_back(1);
            for(int i=1;i<v.size();i++)
                u.push_back(v[i]-v[i-1]);



            cout << (int)u.size()-1 << "\n";
            for(int i=1;i<u.size();i++)
                cout << u[i]-u[i-1] << ' ';
            cout << "\n";
        }
    }
}