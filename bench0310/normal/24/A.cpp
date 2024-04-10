#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<array<int,3>> v[n+1];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back({b,1,c});
        v[b].push_back({a,0,c});
        sum+=c;
    }
    int now=0;
    int a=1;
    int b=v[1][0][0];
    do
    {
        if(v[a][0][0]!=b) swap(v[a][0],v[a][1]);
        if(v[a][0][1]==0) now+=v[a][0][2];
        int t=0;
        if(v[b][0][0]==a) t=1;
        tie(a,b)=make_pair(b,v[b][t][0]);
    } while(a!=1);
    printf("%d\n",min(now,sum-now));
    return 0;
}