#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int la, ra, ta, lb, rb, tb;
    cin>>la>>ra>>ta>>lb>>rb>>tb;
    int d=__gcd(ta, tb), qa=ra-la+1, qb=rb-lb+1, an=0;
    la%=d, lb%=d;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            int nla=la+i*d, nlb=lb+j*d, nqa=qa, nqb=qb;
            if(nla>nlb) nqb-=(nla-nlb);
            else nqa-=(nlb-nla);
            an=max(an, min(nqa, nqb));
        }
    }
    cout<<an;
}