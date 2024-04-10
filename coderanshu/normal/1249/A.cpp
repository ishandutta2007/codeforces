#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,i,j,a[100],n,t=1;
    cin>>q;
    for(i=0;i<q;i++)
    {
        t=1;
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>a[j];
        }
        sort(a,a+n);
        for(j=1;j<n;j++)
        {
            if(a[j]-a[j-1]==1)
            {
                t=2;
                j++;
            }
        }
        cout<<t<<"\n";
    }
    
	return 0;
}