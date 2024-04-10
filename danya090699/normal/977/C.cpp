#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n+2];
    ar[0]=1, ar[n+1]=inf+1;
    for(int a=1; a<=n; a++) cin>>ar[a];
    sort(ar, ar+n+2);
    if(ar[k]!=ar[k+1]) cout<<ar[k];
    else cout<<-1;
}