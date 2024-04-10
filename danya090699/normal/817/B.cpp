#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n;
    cin>>n;
    map <int, int> ma;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        ma[ar[a]]++;
    }
    sort(ar, ar+n);
    int x1=ar[0], x2=ar[1], x3=ar[2];
    if(x1==x2 and x2==x3) cout<<(ma[x1]*(ma[x1]-1)*(ma[x1]-2))/6;
    else if(x1==x2 and x2!=x3) cout<<ma[x3];
    else if(x1!=x2 and x2==x3) cout<<(ma[x2]*(ma[x2]-1))/2;
    else cout<<ma[x3];
}