#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int di[n], q[n];
    for(int a=0; a<n; a++) di[a]=1e9, q[a]=0;
    for(int a=0; a<m; a++)
    {
        int x, y;
        cin>>x>>y;
        x--, y--;
        if(y<x) y+=n;
        q[x]++, di[x]=min(di[x], y-x);
    }
    for(int a=0; a<n; a++)
    {
        int an=0;
        for(int b=0; b<n; b++)
        {
            int p=(a+b)%n;
            if(q[p]) an=max(an, b+(q[p]-1)*n+di[p]);
        }
        cout<<an<<" ";
    }
}