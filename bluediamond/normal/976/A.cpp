#include <bits/stdc++.h>

using namespace std;

int nr0,l,ap1;
char s[105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>l;
    cin.get();
    cin.getline(s,105);
    for(int i=0;i<l;i++)
    {
        if(s[i]=='0')
            nr0++;
        else
            ap1=1;
    }
    if(ap1)
        cout<<1;
    for(int i=1;i<=nr0;i++)
        cout<<0;
    return 0;
}