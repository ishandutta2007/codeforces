#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    long long s;
    scanf("%d%d%d%I64d",&n,&m,&k,&s);
    vector<long long> a(n),b(n);
    for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
    for(int i=0;i<n;i++) scanf("%I64d",&b[i]);
    vector<int> t(m);
    vector<long long> c(m);
    for(int i=0;i<m;i++) scanf("%d%I64d",&t[i],&c[i]);
    int l=-1,r=n;
    vector<pair<int,int>> res(k);
    while(l<r-1)
    {
        int mid=(l+r)/2;
        long long one=a[0],two=b[0];
        int x=1,y=1;
        for(int i=0;i<=mid;i++)
        {
            if(a[i]<one)
            {
                one=a[i];
                x=i+1;
            }
            if(b[i]<two)
            {
                two=b[i];
                y=i+1;
            }
        }
        vector<pair<long long,int>> v(m);
        for(int i=0;i<m;i++)
        {
            if(t[i]==1) v[i].first=one*c[i];
            else v[i].first=two*c[i];
            v[i].second=i;
        }
        sort(v.begin(),v.end());
        long long sum=0;
        for(int i=0;i<k;i++) sum+=v[i].first;
        if(sum<=s)
        {
            r=mid;
            for(int i=0;i<k;i++)
            {
                res[i].first=v[i].second+1;
                if(t[v[i].second]==1) res[i].second=x;
                else res[i].second=y;
            }
        }
        else l=mid;
    }
    if(r<n)
    {
        printf("%d\n",r+1);
        for(pair<int,int> p:res) printf("%d %d\n",p.first,p.second);
    }
    else printf("-1\n");
    return 0;
}