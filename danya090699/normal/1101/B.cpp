#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), l=inf, r=-inf, ty=0;
    for(int a=0; a<n; a++)
    {
        if(ty==0)
        {
            if(s[a]=='[') ty=1;
        }
        else
        {
            if(s[a]==':')
            {
                l=a;
                break;
            }
        }
    }
    ty=0;
    for(int a=n-1; a>=0; a--)
    {
        if(ty==0)
        {
            if(s[a]==']') ty=1;
        }
        else
        {
            if(s[a]==':')
            {
                r=a;
                break;
            }
        }
    }
    if(l<r)
    {
        int an=4;
        for(int a=l+1; a<r; a++) if(s[a]=='|') an++;
        cout<<an;
    }
    else cout<<-1;
}