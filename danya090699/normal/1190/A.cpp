#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    int ar[m];
    for(int a=0; a<m; a++) scanf("%lld", &ar[a]), ar[a]--;
    int yk=0, an=0;
    while(yk<m)
    {
        int q=yk, i=(ar[yk]-q)/k;
        while(yk<n and (ar[yk]-q)/k==i) yk++;
        an++;
    }
    cout<<an;
}