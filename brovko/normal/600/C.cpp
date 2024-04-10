#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

string s;
int k[128];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    for(auto x:s)
        k[x]++;

    int L = 'a', R = 'z';

    while(R > L)
    {
        while(R > L && k[L] % 2 == 0)
            L++;

        while(R > L && k[R] % 2 == 0)
            R--;

        if(R > L)
        {
            k[R]--;
            k[L]++;
        }
    }

    vector <char> v;

    for(int i = 'a'; i <= 'z'; i++)
        if(k[i] % 2)
            v.pb(i);

    for(int i = 'a'; i <= 'z'; i++)
    {
        int x = k[i] / 2;
        k[i] -= x;

        for(int j = 0; j < x; j++)
            cout << (char)i;
    }

    for(auto x:v)
    {
        cout << x;
        k[x]--;
    }

    for(int i = 'z'; i >= 'a'; i--)
    {
        for(int j = 0; j < k[i]; j++)
            cout << (char)i;
    }
}