#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    bool h=0;
    bool e=0;
    bool i1=0;
    bool d=0;
    bool i2=0;
    string s;
    cin>>s;
    for(auto j:s)
    {
        if(j=='h') h=1;
        if(j=='e' && h) e=1;
        if(j=='i' && e) i1=1;
        if(j=='d' && i1) d=1;
        if(j=='i' && d) i2=1;
    }
    if(i2)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}