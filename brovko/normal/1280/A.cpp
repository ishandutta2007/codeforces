#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;
const int MOD=1e9+7;

int t, x;
string s;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> x >> s;
        int sz=s.size();
        int sz2=sz;
        for(int i=0;i<min(x, sz2);i++)
        {
            if(sz<x)
            {
                int y=(int)s[i]-(int)'1';
                //smul(s.substr(i+1, sz-i-1), y);
                while(y--)
                    if(s.size()<x)
                    s+=s.substr(i+1, sz-i-1);
                sz=(sz+(sz-i-1)*((int)s[i]-(int)'1'))%MOD;
                sz2=max(sz2, sz);
            }
            else
            {
                sz=(sz+(sz-i-1)*((int)s[i]-(int)'1'))%MOD;
                sz2=max(sz2, sz);
            }
        }
        cout << (sz+MOD)%MOD << endl;
        s="1";
    }
}