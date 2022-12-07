#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e6+10, inf=1e17;
int pref[sz], mi[sz], ma[sz];
int32_t main() {
    //freopen("input.txt", "r", stdin);
    int n, first;
    cin>>n;
    for(int a=0; a<sz; a++) pref[a]=0, mi[a]=inf, ma[a]=-inf;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        pref[x]+=1;
        ma[x]=x;
        mi[x]=x;
        if(a==0) first=x;
    }
    for(int a=1; a<sz; a++) pref[a]+=pref[a-1], ma[a]=max(ma[a], ma[a-1]);
    for(int a=sz-2; a>=0; a--) mi[a]=min(mi[a], mi[a+1]);
    for(int x=1; x<sz; x++)
    {
        int dl=x*x-first, dr=x*x+x-first, su=0;
        for(int y=x; (y*y)-(x*x+x)<sz; y++)
        {
            int l=y*y-dr, lp=max(0ll, min(sz-1, l)), r=y*y+y-dl, rp=max(0ll, min(sz-1, r));
            int new_dl=max(dl, dr-(mi[lp]-l));
            int new_dr=min(dr, dl+(r-ma[rp]));
            dl=new_dl, dr=new_dr;
            if(dl>dr) break;
            su+=pref[rp];
            if(lp) su-=pref[lp-1];
        }
        if(su==n and dl<=dr and dr>=0)
        {
            cout<<max(dl, 0ll);
            break;
        }
    }
}