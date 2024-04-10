#include<bits/stdc++.h>
using namespace std;
int main()
{
 
    int n;
    cin>>n;
    int a,one[n],two[n],three[n],i,j=0,k=0,l=0;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a==1)
        {
            one[j++]=i;
        }
        else if(a==2)
        {
            two[k++]=i;
        }
        else
        three[l++]=i;
    }
    if(min(l,min(j,k))==0)
    {
        cout<<0;
        return 0;
    }
    else
    {
    cout<<min(l,min(j,k))<<"\n";
    for(i=0;i<min(l,min(j,k));i++)
    {
        cout<<one[i]+1<<" "<<two[i]+1<<" "<<three[i]+1<<"\n";
    }
    }
    return 0; 
}