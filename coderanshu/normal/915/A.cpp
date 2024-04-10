#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,ans,z=1;
    cin>>n>>k;
    int i,b[100];
    for(i=0;i<n;i++)
    {
        cin>>b[i];
        if(k%b[i]==0)
        {
            if(z==1)
            {
            ans=k/b[i];z++;
            }
            else 
            ans=min(ans,k/b[i]);
        }
        
    }
    cout<<ans;
    return 0;
}