#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long long int

int main()
{
    ios_base::sync_with_stdio(0);
    li t,x,y,po2,temp;
    cin>>t;
    while(t--)
    {
        po2=0;
        cin>>x>>y;
        if(x>=y)cout<<"YES\n";
        else
        {
            temp=1;
            while(temp<=x)
            {
                temp*=2;
                po2++;
            }
            if(po2>=3 || pow(3,po2-1)>=y)
            cout<<"YES\n";
            else cout<<"NO\n";
         }
    }
    
    return 0;
}