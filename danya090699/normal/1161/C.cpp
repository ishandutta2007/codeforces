#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, mi=1e9, q=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        mi=min(mi, ar[a]);
    }
    for(int a=0; a<n; a++) if(ar[a]>mi) q++;
    if(q<n/2) cout<<"Bob";
    else cout<<"Alice";
}