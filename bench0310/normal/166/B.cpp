#include <bits/stdc++.h>

using namespace std;

long long cross(array<long long,2> a,array<long long,2> b)
{
    return a[0]*b[1]-a[1]*b[0];
}

array<long long,2> operator-(const array<long long,2> &a,const array<long long,2> &b)
{
    return {a[0]-b[0],a[1]-b[1]};
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<array<long long,2>> v(n);
    for(int i=0;i<n;i++) scanf("%I64d%I64d",&v[i][0],&v[i][1]);
    int q;
    scanf("%d",&q);
    bool ok=1;
    while(q--)
    {
        array<long long,2> a;
        scanf("%I64d%I64d",&a[0],&a[1]);
        if(cross(v[1]-v[0],a-v[0])>=0) ok=0;
        else if(cross(v[n-1]-v[0],a-v[0])<=0) ok=0;
        else
        {
            int l=1,r=n-1;
            int idx=0;
            while(1)
            {
                int m=(l+r)/2;
                if(cross(v[m]-v[0],a-v[0])<=0&&cross(v[m+1]-v[0],a-v[0])>=0)
                {
                    idx=m;
                    break;
                }
                else if(cross(v[m]-v[0],a-v[0])>0) r=m-1;
                else l=m+1;
            }
            if(cross(v[idx+1]-v[idx],a-v[idx])>=0) ok=0;
        }
    }
    if(ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}