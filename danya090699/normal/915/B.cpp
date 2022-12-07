#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, pos, l, r, an;
    cin>>n>>pos>>l>>r;
    if(pos<l)
    {
        an=l-pos+1;
        if(r!=n) an+=r-l+1;
    }
    else if(pos>r)
    {
        an=pos-r+1;
        if(l!=1) an+=r-l+1;
    }
    else
    {
        if(l!=1 and r!=n) an=min(r-pos, pos-l)+(r-l)+2;
        else if(l==1 and r!=n) an=r-pos+1;
        else if(l!=1 and r==n) an=pos-l+1;
        else an=0;
    }
    cout<<an;
}