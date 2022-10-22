#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<ld,int> pli;
typedef pair<pii,string> pps;
typedef pair<char,int> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 5005

int l[MAXN],r[MAXN],ac[MAXN],t[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    for(int i=0;i<q;i++)
    {
        cin >> l[i] >> r[i];
        l[i]--,r[i]--;
        for(int j=l[i];j<=r[i];j++)
            ac[j]++;
    }

    int tot=0;
    for(int i=0;i<n;i++)
        if(ac[i])
            tot++;

    for(int i=0;i<n;i++)
    {
        t[i+1][0]=t[i][0];
        t[i+1][1]=t[i][1];
        if(ac[i]>0 && ac[i]<3)
            t[i+1][ac[i]-1]++;
    }

    int res=0;
    for(int i=0;i<q;i++)
        for(int j=i+1;j<q;j++)
        {
            int f=i,g=j;
            if(l[f]>l[g])
                swap(f,g);
            int r1=tot;
            if(l[g]<=r[f])
            {
                r1-=(t[max(r[f],r[g])+1][0]-t[min(l[f],l[g])][0]);
                r1-=(t[min(r[f],r[g])+1][1]-t[l[g]][1]);
            }
            else
            {
                r1-=(t[r[f]+1][0]-t[l[f]][0]);
                r1-=(t[r[g]+1][0]-t[l[g]][0]);
            }
            res=max(res,r1);
        }
    db(res)

    return 0;
}