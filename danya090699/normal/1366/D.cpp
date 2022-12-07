#include <bits/stdc++.h>
using namespace std;
const int sz=1e7+10;
int di[sz];
main()
{
    for(int a=2; a*a<sz; a++)
    {
        if(di[a]==0)
        {
            for(int b=a+a; b<sz; b+=a) if(!di[b]) di[b]=a;
        }
    }
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int an[2][n];
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        int d=di[x] ? di[x] : x, y=1;
        while(x%d==0) x/=d, y*=d;
        if(x==1) an[0][a]=-1, an[1][a]=-1;
        else an[0][a]=x, an[1][a]=y;
    }
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n; a++) printf("%d ", an[i][a]);
        cout<<"\n";
    }
}