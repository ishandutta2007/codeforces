#include <bits/stdc++.h>

using namespace std;

const int N=300000;
struct interval
{
    int st,dr;
    int ind;
};
bool cmp(interval a,interval b)
{
    if(a.st==b.st)
        return a.dr>b.dr;
    return a.st<b.st;
}
int n;
interval v[N+5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[i]={a,b,i};
    }
    sort(v+1,v+n+1,cmp);
    int dr_max=v[1].dr,poz=1;
    for(int i=2;i<=n;i++)
    {
        if(v[i].dr<=dr_max)
        {
            cout<<v[i].ind<<" "<<v[poz].ind;
            return 0;
        }
        poz=i;
        dr_max=v[i].dr;
    }
    cout<<"-1 -1";
    return 0;
}
/**
**/