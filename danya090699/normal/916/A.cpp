#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int x, h, m, q=0;
    cin>>x>>h>>m;
    while((h%10!=7 and m%10!=7) or q%x!=0)
    {
        m--, q++;
        if(m==-1)
        {
            m=59, h--;
            if(h==-1) h=23;
        }
    }
    cout<<q/x;
}