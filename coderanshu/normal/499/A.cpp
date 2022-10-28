#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,x,a,b=0,count=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        count+=(a-b-1)%x;
        cin>>b;
        count+=b-a+1;
    }
   cout<<count;
    return 0; 
}