#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int nmax=300000;
int n,key,ap[nmax+5],LAST;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    LAST=n+1;
    cout<<"1 ";
    for(int i=1;i<=n;i++)
    {
        cin>>key;
        ap[key]=1;
        while(ap[LAST-1]==1)
            LAST--;
        cout<<i-(n-LAST)<<" ";
    }
    return 0;
}