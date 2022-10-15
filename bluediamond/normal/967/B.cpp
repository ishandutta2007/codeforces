#include <bits/stdc++.h>

using namespace std;

const int N=100000;
int n,a,b;

struct info
{
    int x;
    bool val;
};

bool cmp(info a,info b)
{
    return a.x<b.x;
}

info v[N+5];

int sum=0,value;

bool ok()
{
    if(1LL*value*a>=1LL*b*sum)
        return 1;
    return 0;
}

int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].x;
        sum+=v[i].x;
    }
    v[1].val=1;
    value=v[1].x;
    sort(v+1,v+n+1,cmp);
    int poz=n,cate=0;
    while(!ok())
    {
        if(v[poz].val==1)
        {
            poz--;
            continue;
        }
        cate++;
        sum-=v[poz].x;
        poz--;
    }
    cout<<cate;
    return 0;
}
/**

3*

**/