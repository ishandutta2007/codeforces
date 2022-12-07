#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    double cu=0, su=0;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        if(a<k) cu+=ar[a];
    }
    for(int a=k-1; a<n; a++)
    {
        su+=cu;
        if(a!=n-1) cu+=(ar[a+1]-ar[a-k+1]);
    }
    cout<<fixed<<setprecision(10)<<su/(n-k+1);
}