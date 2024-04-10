#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long int
int main()
{
    ios_base::sync_with_stdio(0);
    li n,i,temp;
    cin>>n;
    li a[n][2],ans[100000]={};
    for(i=0;i<n;i++)
    {
    cin>>a[i][0]>>a[i][1];
    ans[a[i][0]-1]++;
    }
    
    for(i=0;i<n;i++)
    {
        temp=ans[a[i][1]-1]+n-1;
        cout<<temp<<" "<<2*n-2-temp<<"\n";
    }
    
    return 0;
}