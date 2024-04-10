#include<bits/stdc++.h>
using namespace std;
#define l long
int main()
{
    l int n,joy,k,i,z;
    cin>>n>>k;
    l int a,b;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        z=(k<b)?(k-b):0;
        if(i==0)
        joy=a+z;
        else
        joy=max(joy,a+z);
        
    }
    cout<<joy;
    return 0; 
}