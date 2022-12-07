#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, inf=1e8;
    cin>>n>>m;
    int an[n];
    for(int a=0; a<n; a++)
    {
        if(m>=a/2)
        {
            an[a]=a+1;
            m-=a/2;
        }
        else
        {
            if(m==0) an[a]=inf, inf+=n*2;
            else an[a]=a+1-m*2+a, m=0;
        }
    }
    if(m) cout<<-1;
    else
    {
        for(int a=0; a<n; a++) cout<<an[a]<<" ";
    }
}