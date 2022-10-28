#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int m,k,l,count=0;
    cin>>k>>l;
    m=k;
    while(k<l)
    {
        k*=m;
        count++;
    }
    if(k==l)cout<<"YES"<<"\n"<<count;
    else cout<<"NO";
    return 0;
}