#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    sort(ar, ar+n);
    int yk=n-1, an=0;
    while(yk>=0)
    {
        an++;
        bool ok=1;
        if(yk>0)
        {
            if(ar[yk-1]==ar[yk]) ok=0;
        }
        if(ok)
        {
            yk--;
            while(yk>=0)
            {
                    if(ar[yk+1]-ar[yk]<=k) yk--;
                    else break;
            }
        }
        else yk--;
    }
    cout<<an;
}