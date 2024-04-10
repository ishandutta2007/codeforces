#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll int n,m,i,x,y,count=0;
    cin>>n>>m;
    x=1;
    for(i=0;i<m;i++)
    {
        cin>>y;
        (y>=x)?count+=y-x:count+=n+y-x;
        x=y;
    }
    cout<<count;
    return 0;
}