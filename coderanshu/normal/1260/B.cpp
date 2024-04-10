#include<bits/stdc++.h>
using namespace std;
#define li long int
#define lli long long int

int main()
{
    ios_base::sync_with_stdio(0);
   
    li n,c,a,b;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        c=min(a,b);
        a=max(a,b);
        if(c*2==a)
        {
            cout<<"YES\n";
        }
        else
        {
            if((2*c-a)%3==0 && 2*c-a>0)
            cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}