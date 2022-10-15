#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int nmax=200000;
int n,v[nmax+5],use[nmax+5],ap[nmax+5],sol[nmax+5],folosesc[nmax+5],step=1,cost;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        {
            cin>>v[i];
            use[v[i]]++;
            ap[v[i]]++;
        }
    while(ap[step])
        step++;
    for(int i=1;i<=n;i++)
    {
        if(use[v[i]]>=2 or folosesc[v[i]]==1)
        {
            int val1=v[i],val2=step;
            ///cout<<val1<<" "<<val2<<"\n\n";
            if(val1<val2 and folosesc[val1]==0)
            {
                sol[i]=val1;
                folosesc[val1]=1;
                use[v[i]]--;
                continue;
            }
            use[v[i]]--;
            cost++;
            sol[i]=step;
            ap[step]=1;
            while(ap[step])
                step++;
            continue;
        }
        sol[i]=v[i];
        folosesc[v[i]]=1;
    }
    cout<<cost<<"\n";
    for(int i=1;i<=n;i++)
        cout<<sol[i]<<" ";
    return 0;
}
/**
**/