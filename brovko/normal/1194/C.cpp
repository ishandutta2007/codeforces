#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s, t, p;
int q;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> q;
    while(q--)
    {
        cin >> s >> t >> p;
        string x="";
        int k=0;
        for(int i=0;i<t.size();i++)
        {
            if(k<s.size() && t[i]==s[k])
                k++;
            else x+=t[i];
        }

        int f=0;

        if(k==s.size())
            f=1;

        sort(p.begin(), p.end());
        sort(x.begin(), x.end());

        k=0;
        for(int i=0;i<p.size();i++)
        {
            if(k<x.size() && p[i]==x[k])
                k++;
        }

        if(k!=x.size())
            f=0;
        if(f==0)
            cout << "NO" << endl;
        else cout << "YES" << endl;
    }

}