#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,l,i;
    cin>>n>>l;
    double a[n],M;
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    M=max(2*a[0],2*(l-a[n-1]));
    for(i=0;i<n-1;i++)
    {
        M=max(M,a[i+1]-a[i]);
    }
    cout<<fixed<<setprecision(10)<<M/2;
    return 0;
}