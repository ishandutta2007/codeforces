#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k1, k2;
    cin>>n>>k1>>k2;
    int ar[2][n], k=k1+k2, di[n];
    for(int a=0; a<2; a++) for(int b=0; b<n; b++) cin>>ar[a][b];
    for(int a=0; a<n; a++) di[a]=abs(ar[0][a]-ar[1][a]);
    for(int a=0; a<k; a++)
    {
        int be=-1, bnu;
        for(int b=0; b<n; b++)
        {
            if(di[b]>be)
            {
                be=di[b], bnu=b;
            }
        }
        if(be) di[bnu]--;
        else di[bnu]++;
    }
    int an=0;
    for(int a=0; a<n; a++) an+=di[a]*di[a];
    cout<<an;
}