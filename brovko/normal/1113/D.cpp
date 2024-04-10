#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s, t;
int n;

int pal()
{
    for(int i=0;i<n;i++)
        if(t[i]!=t[n-1-i])
            return 0;
    return 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> s;
    n=s.size();

    int f=0;

    for(int i=1;i<n/2;i++)
        if(s[i]!=s[i-1])
            f=1;
    if(f==0)
    {
        cout << "Impossible";
        return 0;
    }

    for(int i=0;i<n/2;i++)
    {
        t=s.substr(i+1, n-i-1)+s.substr(0, i+1);
        if(s!=t && pal()==1)
        {
            cout << 1;
            return 0;
        }
    }
    cout << 2;
}