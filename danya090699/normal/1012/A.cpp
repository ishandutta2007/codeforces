#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n*2];
    for(int a=0; a<n*2; a++) scanf("%d", &ar[a]);
    sort(ar, ar+n*2);
    long long an=1ll*(ar[n-1]-ar[0])*(ar[n*2-1]-ar[n]);
    for(int a=1; a+n<=n*2; a++) an=min(an, 1ll*(ar[n*2-1]-ar[0])*(ar[a+n-1]-ar[a]));
    cout<<an;
}