#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m,k,i;
    cin>>n>>m>>k;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n,greater<>());
    i=0;
    while(k<m && a[i]!=1 && i<n)
    {
        k+=a[i++]-1;
    }
    if(k>=m)cout<<i;
    else cout<<-1;
    return 0;
}