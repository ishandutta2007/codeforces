#include <bits/stdc++.h>
using namespace std;
const int sz=35e5;
map <char, int> bor[sz];
int va[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q=1;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<(1<<15); a++)
    {
        int s=0;
        for(int b=0; b+1<n; b++)
        {
            char d=__builtin_popcount((ar[b]&((1<<15)-1))^a);
            d-=__builtin_popcount((ar[b+1]&((1<<15)-1))^a);
            if(bor[s].find(d)==bor[s].end()) bor[s][d]=q++;
            s=bor[s][d];
        }
        va[s]=a;
    }
    for(int a=0; a<(1<<15); a++)
    {
        int s=0, ok=1;
        for(int b=0; b+1<n; b++)
        {
            char d=__builtin_popcount((ar[b+1]>>15)^a);
            d-=__builtin_popcount((ar[b]>>15)^a);
            if(bor[s].find(d)==bor[s].end())
            {
                ok=0;
                break;
            }
            s=bor[s][d];
        }
        if(ok)
        {
            cout<<(a<<15)+va[s];
            return 0;
        }
    }
    cout<<-1;
}