#include <bits/stdc++.h>
using namespace std;
const int nmax=100000;
int n,v[nmax+5],S,first[2*nmax+5],ans=0;
#define first (first+nmax)
char ch;
int main()
{
    cin>>n;
    for(int i=-n;i<=n;i++)
        first[i]=-1;
    cin.get();
    first[0]=0;
    for(int i=1;i<=n;i++)
    {
        ch=cin.get();
        v[i]=ch-'0';
        if(ch=='0')
            v[i]=-1;
        S+=v[i];
        if(first[S]==-1)
        {
            first[S]=i;
            continue;
        }
        ans=max(ans,i-first[S]);
    }
    cout<<ans;
    return 0;
}