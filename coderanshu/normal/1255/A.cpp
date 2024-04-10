#include<bits/stdc++.h>
using namespace std;
#define li long int
#define lli long long int
li mod(li x)
{
    return (x>0)?x:-x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t ;
    li a,b,z,ans;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        z=mod(a-b);
        ans=z/5+(z%5)/2+((z%5)%2);
        cout<<ans<<"\n";
    }
    return 0;
}