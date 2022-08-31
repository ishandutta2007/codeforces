#include<bits/stdc++.h>
using namespace std;
int main()
{
    long double n,k,ans;
    cin>>n>>k;
    ans=(int)ceil(k/n);
    cout<<fixed<<setprecision(0)<<ans<<endl;
    return 0;
}