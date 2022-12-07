#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ra=0, un=0, px, py;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x, y;
        cin>>x>>y;
        if(x!=y) ra=1;
        if(a>0)
        {
            if(x>px) un=1;
        }
        px=x, py=y;
    }
    if(ra) cout<<"rated";
    else
    {
        if(un) cout<<"unrated";
        else cout<<"maybe";
    }
}