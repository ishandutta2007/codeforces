#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, d, an=0;
    cin>>n>>d;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    sort(ar, ar+n);
    for(int a=0; a<n; a++)
    {
        int q=0;
        for(int b=a; b<n; b++) if(ar[b]-ar[a]<=d) q++;
        an=max(an, q);
    }
    cout<<n-an;
}