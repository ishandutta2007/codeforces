#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N=1000+5;

int n;
ld a;

struct info
{
    int p;
    ld l;
};

info v[N];

bool cmp(info a,info b)
{
    return a.p<b.p;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>a;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].p>>v[i].l;
        v[i].l*=0.5;
    }
    sort(v+1,v+n+1,cmp);
    int ans=2;
    for(int i=1;i<n;i++)
    {
        ld p1=v[i].p+v[i].l;
        ld p2=v[i+1].p-v[i+1].l;
        ld space=p2-p1;
        ans+=(space>=a);
        ans+=(space>a);
    }
    cout<<ans<<"\n";
    return 0;
}

/**
**/