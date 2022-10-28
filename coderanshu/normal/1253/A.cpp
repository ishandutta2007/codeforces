#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long long int

int main()
{
    ios_base::sync_with_stdio(0);
    int t,a[100002],b[100002],i,c[100002],n,k,f;
    set <int> s;
    set<int>::iterator it;
    cin>>t;
    while(t--)
    {
        f=0;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            cin>>b[i];
            c[i]=b[i]-a[i];
        }
        for(i=0;i<n;i++)
        {
            k=c[i];
            if(k<0)
            {
                f=-1;break;
            }
            if(k!=0)
            {
                f++;
                while(c[i]==k && i<n){i++;}
                i--;
            }
            if(f>1)
            {
                f=-1;break;
            }
        }
        if(f==1 || f==0)cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    
    return 0;
}