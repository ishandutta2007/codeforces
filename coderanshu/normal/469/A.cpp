#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)a[i]=0;
    int p,x;
    cin>>p;
    for(i=0;i<p;i++)
    {
        cin>>x;
        a[x-1]=1;
    }
    cin>>p;
    for(i=0;i<p;i++)
    {
        cin>>x;
        a[x-1]=1;
    }
    p=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
        p=1;break;
        }
    }
    if(p==1)
    cout<<"Oh, my keyboard!";
    else cout<<"I become the guy.";
    return 0; 
}