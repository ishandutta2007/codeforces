#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int ar[sz];
int dfs(int l, int r, int i)
{
    if(i==0) return ar[l]^ar[r];

    if((ar[l]&(1<<i)) or (ar[r]&(1<<i))==0) return dfs(l, r, i-1);

    for(int a=l; ; a++)
    {
        if(ar[a]&(1<<i))
        {
            return (1<<i)+min(dfs(l, a-1, i-1), dfs(a, r, i-1));
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    sort(ar, ar+n);
    cout<<dfs(0, n-1, 29);
}