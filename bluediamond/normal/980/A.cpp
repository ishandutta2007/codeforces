#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s;
    int _=0;
    int o=0;
    for(auto &it:s)
    {
        if(it=='-')
        {
            _++;
        }
        if(it=='o')
        {
            o++;
        }
    }
    if(o==0)
    {
        cout<<"YES\n";
        return 0;
    }
    if(_%o==0)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
    cout<<o<<" "<<_<<"\n";
    return 0;
}