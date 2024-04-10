#include <bits/stdc++.h>
using namespace std;
int de(int x, int y)
{
    return x/y+(x%y>0);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    sort(ar, ar+n);
    int yk=0, an=0;
    for(int a=1; a<=k; a++)
    {
        int q;
        scanf("%d", &q);
        while(yk<n and ar[yk]<a) yk++;
        an=max(an, de(n-yk, q));
    }
    cout<<an<<"\n";
    for(int a=0; a<an; a++)
    {
        printf("%d", de(n-a, an));
        for(int b=a; b<n; b+=an) printf(" %d", ar[b]);
        printf("\n");
    }
}