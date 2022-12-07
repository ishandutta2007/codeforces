#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    k++;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    sort(ar, ar+n);
    cout<<(m-m/k)*ar[n-1]+(m/k)*ar[n-2];
}