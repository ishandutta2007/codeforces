#include <bits/stdc++.h>
using namespace std;
const int inf=2e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, d, cu=0, an=0, ma=inf;
    cin>>n>>d;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        cu+=x;
        ma=max(ma, cu);
        if(cu>d)
        {
            an=-1;
            break;
        }
        if(x==0)
        {
            if(cu<0)
            {
                if(ma<d)
                {
                    int add=min(-cu, d-ma);
                    cu+=add, ma+=add;
                }
                if(cu<0)
                {
                    cu=0, ma=0, an++;
                }
            }
        }
    }
    cout<<an;
}