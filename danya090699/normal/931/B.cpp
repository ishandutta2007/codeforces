#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, y, q=1;
    cin>>n>>x>>y;
    x--, y--;
    for(int a=2; a<=n; a*=2)
    {
        if(x/a==y/a)
        {
            if(a==n) cout<<"Final!";
            else cout<<q;
            break;
        }
        q++;
    }
}