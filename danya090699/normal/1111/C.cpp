#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e5+10;
int ar[sz], n, k, A, B;
int dfs(int l, int r, int lg, int rg)
{
    //cout<<l<<" "<<r<<"  "<<lg<<" "<<rg<<"\n";
    if(lg==rg) return A;
    else
    {
        if(l==r) return B*(rg-lg);
        else
        {
            int mid=(l+r)>>1;
            int md=upper_bound(ar+lg, ar+rg, mid)-ar;
            //if(mid==3) cout<<md<<" ";
            int lv=dfs(l, mid, lg, md), rv=dfs(mid+1, r, md, rg);
            return min(lv+rv, B*(rg-lg)*(r-l+1));
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k>>A>>B;
    for(int a=0; a<k; a++)
    {
        scanf("%lld", &ar[a]);
        ar[a]--;
    }
    sort(ar, ar+k);
    cout<<dfs(0, (1<<n)-1, 0, k);
}