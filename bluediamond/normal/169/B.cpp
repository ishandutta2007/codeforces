#include <bits/stdc++.h>

using namespace std;

int f[15];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s,a;
    cin>>s>>a;
    for(auto x:a)
    {
        f[x-'0']++;
    }
    int MX=9;
    for(auto x:s)
    {
        while(MX && f[MX]==0)
        {
            MX--;
        }
        if(f[MX]==0 || x-'0'>=MX)
        {
            cout<<x-'0';
        }
        else
        {
            cout<<MX;
            f[MX]--;
        }
    }
    cout<<"\n";
    return 0;
}