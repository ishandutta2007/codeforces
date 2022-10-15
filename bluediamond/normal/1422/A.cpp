#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;



int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int tt;
        cin>>tt;
        while (tt--)
        {
                ll a,b,c;
                cin>>a>>b>>c;
                a+=b;
                a+=c;
                a--;
                cout<<a<<"\n";
        }


}