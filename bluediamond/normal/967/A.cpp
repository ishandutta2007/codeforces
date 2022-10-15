#include <bits/stdc++.h>

using namespace std;

int n,s,v[105];

void afis(int time)
{
    cout<<time/60<<" "<<time%60;
}

int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        int h,m;
        cin>>h>>m;
        v[i]=60*h+m;
    }
    sort(v+1,v+n+1);
    if(v[1]>s)
    {
        afis(0);
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        if(v[i+1]-v[i]>=2*s+2)
        {
            afis(v[i]+s+1);
            return 0;
        }
    }
    afis(v[n]+s+1);
    return 0;
}
/**

**/