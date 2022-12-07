#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int x, y, z, a, b, c;
    cin>>x>>y>>z>>a>>b>>c;
    if(x<=a)
    {
        a-=x;
        if(a+b>=y and a+b+c>=y+z) cout<<"YES";
        else cout<<"NO";
    }
    else cout<<"NO";
}