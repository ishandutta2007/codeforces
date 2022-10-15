#include <bits/stdc++.h>

using namespace std;

const int nmax=100000;
int n,v[nmax+5];
long long ans=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(int i=1;i<=n;i++)
    {
        for(long long P=0;P<=35;P++)
        {
            long long X=(1LL<<P),caut=X-v[i];
            if(caut<=0)
                continue;
            int r1=0,r2=0,pas=(1<<16);
            while(pas)
            {
                if(r1+pas<=n and v[r1+pas]<caut)
                    r1+=pas;
                pas/=2;
            }
            r1++;
            pas=(1<<16);
            while(pas)
            {
                if(r2+pas<=n and v[r2+pas]<=caut)
                    r2+=pas;
                pas/=2;
            }
            if(v[r1]==caut)
                ans+=r2-r1+1;
            if(v[i]==caut)
                ans--;
        }
    }
    cout<<ans/2;
	return 0;
}
/**


**/