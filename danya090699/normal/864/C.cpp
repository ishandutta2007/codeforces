//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, f, k, cu, q=0;
    cin>>n>>m>>f>>k;
    cu=m;
    for(int a=0; a<k; a++)
    {
        int d1=f;
        if(a%2==1) d1=n-f;
        if(cu<d1)
        {
            q=-1;
            break;
        }
        cu-=d1;
        int d2;
        if(a%2==0)
        {
            d2=n-f;
            if(a!=k-1) d2*=2;
        }
        else
        {
            d2=f;
            if(a!=k-1) d2*=2;
        }
        if(cu<d2)
        {
            cu=m;
            if(cu<d2)
            {
                q=-1;
                break;
            }
            else q++;
        }
        cu-=n-d1;
    }
    cout<<q;
}