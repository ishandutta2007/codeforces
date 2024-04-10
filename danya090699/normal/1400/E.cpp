#include <bits/stdc++.h>
using namespace std;
const int sz=5e3+10;
int q[sz];
int dfs(int l, int r)
{
    int dp=r-l+1;
    int mi=2e9;
    for(int a=l; a<=r; a++) mi=min(q[a], mi);
    for(int a=l; a<=r; a++) q[a]-=mi;
    int yk=l, su=mi;
    while(yk<=r)
    {
        if(q[yk])
        {
            int l2=yk;
            while(yk<=r and q[yk]) yk++;
            su+=dfs(l2, yk-1);
        }
        else yk++;
    }
    dp=min(dp, su);
    return dp;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++) cin>>q[a];
    cout<<dfs(0, n-1);
}