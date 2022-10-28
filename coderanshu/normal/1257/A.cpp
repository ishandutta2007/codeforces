#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long int
int mod(int n)
{
    return (n>0)?n:-n;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,x,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>a>>b;
        cout<<min(n-1,mod(b-a)+x)<<"\n";
    }
    
    return 0;
}