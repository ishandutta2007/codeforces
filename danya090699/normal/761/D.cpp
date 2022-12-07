//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, l, r, pos=1, pr=-2e9;
    cin>>n>>l>>r;
    int ara[n], arc[n], so[n];
    for(int a=0; a<n; a++) cin>>ara[a];
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        x--;
        so[x]=a;
    }
    for(int a=0; a<n; a++)
    {
        int nu=so[a];
        int lg=l-ara[nu], rg=r-ara[nu];
        if(pr+1<lg) arc[nu]=lg;
        else
        {
            if(pr+1<=rg) arc[nu]=pr+1;
            else
            {
                pos=0;
                break;
            }
        }
        pr=arc[nu];
        //cout<<arc[nu]<<" ";
    }
    if(pos)
    {
        for(int a=0; a<n; a++) cout<<ara[a]+arc[a]<<" ";
    }
    else cout<<-1;
}