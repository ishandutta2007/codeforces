#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n*2];
    for(int a=0; a<n*2; a++) scanf("%d", &ar[a]);
    sort(ar, ar+n*2);
    if(ar[0]==ar[n*2-1]) cout<<-1;
    else
    {
        for(int a=0; a<n*2; a++) printf("%d ", ar[a]);
    }
}