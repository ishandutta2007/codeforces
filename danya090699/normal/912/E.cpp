#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18, sz=20;
int n, ar[sz];
vector <int> sp[2];
void rec(int x, int nu)
{
    for(int a=nu; a<n; a+=2)
    {
        if(inf/ar[a]>=x) rec(x*ar[a], a);
    }
    sp[nu%2].push_back(x);
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++) cin>>ar[a];
    rec(1, 0), rec(1, 1);
    sort(sp[0].begin(), sp[0].end());
    sort(sp[1].begin(), sp[1].end());
    int k;
    cin>>k;
    int l=0, r=inf;
    while(r-l>1)
    {
        int mid=(l+r)>>1, yk=sp[1].size()-1, q=0;
        for(int a=0; a<sp[0].size(); a++)
        {
            while(yk>=0)
            {
                if(mid/sp[0][a]<sp[1][yk]) yk--;
                else break;
            }
            q+=yk+1;
        }
        if(q>=k) r=mid;
        else l=mid;
    }
    cout<<r;
}