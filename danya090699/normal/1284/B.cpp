#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10, inf=1e9;
int q[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int la[n];
    for(int a=0; a<n; a++)
    {
        int m, fi;
        scanf("%d", &m);
        la[a]=inf;
        for(int b=0; b<m; b++)
        {
            int x;
            scanf("%d", &x);
            if(b==0) fi=x;
            if(x<=la[a]) la[a]=x;
            else la[a]=-1;
        }
        if(la[a]!=-1) q[fi]++;
    }
    for(int a=1; a<sz; a++) q[a]+=q[a-1];
    long long an=1ll*n*n;
    for(int a=0; a<n; a++) if(la[a]!=-1) an-=q[la[a]];
    cout<<an;
}