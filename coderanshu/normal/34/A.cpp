#include<bits/stdc++.h>
using namespace std;
int mod(int x)
{
    return (x>0)?x:-x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n,i,d,f=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    d=mod(a[1]-a[0]);
    for(i=2;i<n;i++)
    {
        if(mod(a[i]-a[i-1])<d)
        {
            d=mod(a[i]-a[i-1]);
            f=i-1;
        }
    }
    if(mod(a[n-1]-a[0])<d)
    cout<<n<<" "<<1;
    else cout<<f+2<<" "<<f+1;
    return 0;
}