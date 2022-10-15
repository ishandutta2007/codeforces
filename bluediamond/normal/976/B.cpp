#include <bits/stdc++.h>

using namespace std;

long long n,m,k;
long long ramas,r,c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cin>>n>>m>>k;
    k++;
    if(k<=n)
    {
        cout<<k<<" 1";
        return 0;
    }
    k-=n;
    ramas=k/(m-1);
    if(k%(m-1)==0)
        r=n+1-ramas;
    else
        r=n-ramas;
    k-=(n-r)*(m-1);
    //cout<<k<<"\n\n";
    cout<<r<<" ";
    if(r%2==0)
        cout<<k+1;
    else
        cout<<m+1-k;
    return 0;
}