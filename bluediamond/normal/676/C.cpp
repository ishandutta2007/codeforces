#include <bits/stdc++.h>
using namespace std;
const int nmax=100000;
int n,k,v[nmax+5],ans;
int main()
{
    cin>>n>>k;
    cin.get();
    for(int i=1;i<=n;i++)
    {char ch;
        ch=cin.get();
        v[i]=ch-'a';
    }
    int start=1,nrdif=0;
    ///0
    for(int i=1;i<=n;i++)
    {
        if(v[i]==1)
            nrdif++;
        while(nrdif>k)
        {
            if(v[start]==1)
                nrdif--;
            start++;
        }
        ans=max(ans,i-start+1);
    }
    start=1,nrdif=0;
    ///1
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0)
            nrdif++;
        while(nrdif>k)
        {
            if(v[start]==0)
                nrdif--;
            start++;
        }
        ans=max(ans,i-start+1);
    }cout<<ans;
    return 0;
}
/**

**/