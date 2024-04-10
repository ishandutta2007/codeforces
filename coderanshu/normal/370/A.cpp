#include<bits/stdc++.h>
using namespace std;
// nice concept of 2d array
int mod(int x)

{
    return (x>0)?x:-x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    if(r1==r2 || c1==c2)
    cout<<1;
    else cout<<2;
    cout<<" ";
    if(r1-r2==c1-c2 || r1-r2+c1-c2==0)
    cout<<1;
    else if((r1+c1)%2==(r2+c2)%2)
    cout<<2;
    else cout<<0;
    cout<<" ";
    cout<<mod(r2-r1)+mod(c2-c1)-min(mod(r2-r1),mod(c2-c1));
    return 0;
}