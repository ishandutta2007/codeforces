#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ma=-1, bch=-1, bne=-1;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        ma=max(ma, ar[a]);
    }
    for(int a=n; a>1; a--)
    {
        if(a%2==0)
        {
            int x=(a-2)/2;
            bch=max(bch, max(ar[x], ar[x+1]));
            bch=max(bch, max(ar[n-x-1], ar[n-x-2]));
            cout<<bch<<" ";
        }
        else
        {
            int x=(a-3)/2;
            bne=max(bne, max(min(ar[x], ar[x+1]), min(ar[x+1], ar[x+2])));
            bne=max(bne, max(min(ar[n-x-3], ar[n-x-2]), min(ar[n-x-2], ar[n-x-1])));
            cout<<bne<<" ";
        }
    }
    cout<<ma;
}