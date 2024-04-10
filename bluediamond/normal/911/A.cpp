#include <bits/stdc++.h>
using namespace std;
const int NMAX=100000;
int n,v[NMAX+5],MIN=1e9,BEST=1e9;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        MIN=min(MIN,v[i]);
    }
    int last=-1e9;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==MIN)
        {
            BEST=min(BEST,i-last);
            last=i;
        }
    }
    cout<<BEST;
    return 0;
}
/**
**/