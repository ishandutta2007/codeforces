#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int x, y, sw=0;
    cin>>x>>y;
    if(x>y)
    {
        swap(x, y), sw=1;
    }
    char an;
    if(x==y) an='=';
    else
    {
        if(x==1) an='<';
        else if(x==2)
        {
            if(y==3) an='<';
            else if(y==4) an='=';
            else an='>';
        }
        else an='>';
    }
    if(sw)
    {
        if(an=='<') an='>';
        else if(an=='>') an='<';
    }
    cout<<an;
}