#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
const int sz=1e6+10;
int q[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int gr[n][2], pro[m][2];
    for(int a=0; a<n; a++) cin>>gr[a][0]>>gr[a][1];
    for(int a=0; a<m; a++) cin>>pro[a][0]>>pro[a][1];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            if(gr[a][0]<=pro[b][0] and gr[a][1]<=pro[b][1])
            {
                q[pro[b][0]-gr[a][0]]=max(q[pro[b][0]-gr[a][0]], pro[b][1]-gr[a][1]+1);
            }
        }
    }
    int an=1e9;
    for(int a=sz-1; a>=0; a--)
    {
        an=min(an, a+q[a]);
        if(a) q[a-1]=max(q[a-1], q[a]);
    }
    cout<<an;
}