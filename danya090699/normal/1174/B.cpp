#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    set <int> se;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]), se.insert(ar[a]&1);
    if(se.size()==2) sort(ar, ar+n);
    for(int a=0; a<n; a++) printf("%d ", ar[a]);
}