#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m=0;
    cin>>n;
    int x[n], x2[n], y[n], y2[n], an[n][4];
    for(int a=0; a<n; a++)
    {
        cin>>x[a];
        x[a]--, x2[x[a]]=a;
    }
    for(int a=0; a<n; a++)
    {
        cin>>y[a];
        y[a]--, y2[y[a]]=a;
    }
    for(int a=0; a<n; a++)
    {
        int nx=x2[a];
        swap(x[a], x[nx]), swap(x2[x[a]], x2[x[nx]]);
        int ny=y2[a];
        swap(y[a], y[ny]), swap(y2[y[a]], y2[y[ny]]);
        if(nx!=a or ny!=a)
        {
            an[m][0]=nx, an[m][1]=a, an[m][2]=a, an[m][3]=ny, m++;
        }
    }
    cout<<m<<"\n";
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<4; b++) cout<<an[a][b]+1<<" ";
        cout<<"\n";
    }
}