#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
main()
{
ll i;
ll p=1;
ll w,h;
cin>>w>>h;
for(i=1;i<=w+h;i++)
{
    p=(p*2)%998244353;
}
cout<<p;
}