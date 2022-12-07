#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, m, k;
        cin>>n>>m>>k;
        k=min(k, m-1);
        int an=0, ar[n];
        for(int a=0; a<n; a++) cin>>ar[a];
        for(int a=0; a<=k; a++)
        {
            int x=2e9;
            for(int b=a; b+n-m<a+(n-k); b++) x=min(x, max(ar[b], ar[b+n-m]));
            an=max(an, x);
        }
        cout<<an<<"\n";
    }
}