#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <int> pa, sta;
    for(int a=0; a<n; a++)
    {
        char sy;
        cin>>sy;
        if(sy=='P') pa.push_back(a);
        if(sy=='*') sta.push_back(a);
    }
    int l=0, r=2*n;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        int yk=0;
        for(int a=0; a<pa.size(); a++)
        {
            int cl=pa[a], cr=pa[a];
            while(yk<sta.size())
            {
                cl=min(cl, sta[yk]), cr=max(cr, sta[yk]);
                if((cr-cl)+min(pa[a]-cl, cr-pa[a])<=mid) yk++;
                else break;
            }
        }
        if(yk==sta.size()) r=mid;
        else l=mid;
    }
    cout<<r;
}