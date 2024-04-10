//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, an=0;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    sort(ar, ar+n);
    for(int a=0; a<n; a++)
    {
        if(ar[a]<=k*2) k=max(k, ar[a]);
        else
        {
            while(ar[a]>k*2)
            {
                k*=2, an++;
            }
            k=ar[a];
        }
    }
    cout<<an;
}