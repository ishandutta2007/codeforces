#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

using li = long long;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        int n = s.size();

        vector <int> v;
        int kp = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '?')
                v.pb(i);

            if(s[i] == '(')
                kp++;
        }

        if(v.size() == 0)
        {
            cout << "YES\n";
            continue;
        }

        int d = n / 2 - kp;

        for(int i = 0; i < d; i++)
        {
            s[v[i]] = '(';
        }

        for(int i = d; i < v.size(); i++)
            s[v[i]] = ')';

//        cout << 1 << endl;

        int F = 1;

//        if(v.size() > 0)
//        {


            if(d == v.size() || d == 0)
            {
                cout << "YES\n";
                continue;
            }

            s[v[d - 1]] = ')';
            s[v[d]] = '(';
//        }

//        if(F == 0)
//            continue;



        int x = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                x++;
            else x--;

            if(x < 0)
                F = 0;
        }

        cout << (F == 0 ? "YES\n" : "NO\n");
    }
}