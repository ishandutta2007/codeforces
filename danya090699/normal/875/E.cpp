#include <bits/stdc++.h>
using namespace std;
int mo(int x)
{
    if(x<0) return -x;
    else return x;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, s1, s2;
    cin>>n>>s1>>s2;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    int l=mo(s1-s2)-1, r=1e9+10;
    while(r-l>1)
    {
        int mid=(l+r)>>1, pr=s1;
        set <int> dp;
        dp.insert(s2);
        for(int a=0; a<n; a++)
        {
            if(dp.size()==0) break;
            while(dp.size()>0)
            {
                int x=*dp.begin();
                if(ar[a]-mid>x) dp.erase(dp.begin());
                else break;
            }
            while(dp.size()>0)
            {
                set <int>::iterator it=dp.end();
                it--;
                int x=*it;
                if(ar[a]+mid<x) dp.erase(it);
                else break;
            }
            if(mo(ar[a]-pr)<=mid) dp.insert(pr);
            pr=ar[a];
        }
        if(dp.size()==0) l=mid;
        else r=mid;
    }
    cout<<r;
}