#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
bool us[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int x, y, c, i=1, fo=-1;
    cin>>x>>y>>c;
    x=x%y;
    while(fo==-1)
    {
        if(us[x]) break;
        us[x]=1;
        x*=10;
        if(x/y==c) fo=i;
        x=x%y, i++;
    }
    cout<<fo;
}