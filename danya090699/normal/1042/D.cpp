#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10;
int ar[sz], an=0, t;
void dfs(int l, int r)
{
    if(l==r)
    {
        if(ar[l]<t) an++;
    }
    else
    {
        int mid=(l+r)>>1, su=0;
        vector <int> ll, rr;
        for(int a=mid; a>=l; a--) su+=ar[a], ll.push_back(su);
        su=0;
        for(int a=mid+1; a<=r; a++) su+=ar[a], rr.push_back(su);
        sort(ll.begin(), ll.end());
        sort(rr.begin(), rr.end());
        int yk=rr.size()-1;
        for(int a=0; a<ll.size(); a++)
        {
            while(yk>=0)
            {
                if(ll[a]+rr[yk]>=t) yk--;
                else break;
            }
            an+=yk+1;
        }
        dfs(l, mid), dfs(mid+1, r);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n>>t;
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    dfs(0, n-1);
    cout<<an;
}