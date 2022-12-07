#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], ql=0, qr=0;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=0; ar[a]==ar[0]; a++) ql++;
    for(int a=n-1; ar[a]==ar[0]; a--) qr++;
    cout<<n-1-min(ql, qr);
}