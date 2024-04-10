#include <bits/stdc++.h>
using namespace std;
const int nmax=100,inf=1000000000;
int v[(nmax+5)*(nmax+5)],n,last[(nmax+5)*(nmax+5)],strat;
int main()
{
    cin>>n;
    for(int st=0;st<=n;st++)
    {
        for(int dr=st+1;dr<=n;dr++)
        {
            int mindif=inf,poz=-1;
            for(int i=1;i<=strat;i++)///bag pe i
            {
                if(st>=last[i] and st-last[i]<=mindif)
                {
                    mindif=st-last[i];
                    poz=i;
                }
            }
            if(poz==-1)
                last[++strat]=dr;
            else
                last[poz]=dr;
        }
    }
    cout<<strat;
    return 0;
}
/**

**/