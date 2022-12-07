#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=inf;
    cin>>n;
    if(n==1) cout<<0;
    else
    {
        int ar[n];
        for(int a=0; a<n; a++) cin>>ar[a];
        for(int add=-1; add<=1; add++)
        {
            for(int add2=-1; add2<=1; add2++)
            {
                int cu=abs(add)+abs(add2), d=(ar[1]+add2)-(ar[0]+add), pr=(ar[1]+add2);
                for(int a=2; a<n; a++)
                {
                    int va=pr+d;
                    if(abs(ar[a]-va)>1)
                    {
                        cu=inf;
                        break;
                    }
                    else cu+=abs(ar[a]-va);
                    pr=va;
                }
                an=min(an, cu);
            }
        }
        if(an==inf) cout<<-1;
        else cout<<an;
    }
}