#include <bits/stdc++.h>
#define int long long
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    for(int a=0; a<min(n, m); a++)
    {
        for(int b=0; b<min(n, m); b++)
        {
            int x=(a+1)%m, y=(b+1)%m;
            if((x*x+y*y)%m==0)
            {
                an+=de(n-a, m)*de(n-b, m);
            }
        }
    }
    cout<<an;
}