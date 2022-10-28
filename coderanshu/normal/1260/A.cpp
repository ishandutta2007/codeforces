#include<bits/stdc++.h>
using namespace std;
#define li long int
#define lli long long int

int main()
{
    ios_base::sync_with_stdio(0);
   
    li n,c,sum;
    cin>>n;
    while(n--)
    {
        cin>>c>>sum;
        cout<<(sum/c+1)*(sum%c)*(sum/c+1)+(sum/c)*(c-sum%c)*(sum/c)<<"\n";
    }
    return 0;
}