#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int an[n][n];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            if(a&1) an[b][a]=a*n+b;
            else an[b][a]=a*n+n-1-b;
        }
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++) cout<<an[a][b]+1<<" ";
        cout<<"\n";
    }
}