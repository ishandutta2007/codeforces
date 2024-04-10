#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=200000;

struct point
{
    int x,y;
};
bool cmp(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int n;
point v[N+5];
int cnt=0;

map<int,int>mp; /// pentru coord .y

ll sol=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i].x>>v[i].y;
    sort(v+1,v+n+1,cmp);
    int p=1;
    while(p<=n)
    {
        int init=p;
        while(p+1<=n && v[p+1].x==v[init].x)
            p++;
        int dif=p-init+1;
        sol+=(ll)dif*(dif-1)/2;
        for(int j=init;j<=p;j++)
        {
            sol+=mp[v[j].y];
        }
        for(int j=init;j<=p;j++)
        {
            mp[v[j].y]++;
        }
        p++;
    }
    cout<<sol<<"\n";
    return 0;
}
/**

**/