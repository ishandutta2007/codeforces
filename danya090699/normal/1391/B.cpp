#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, an=0;
        cin>>n>>m;
        char fi[n][m];
        for(int a=0; a<n; a++) for(int b=0; b<m; b++) cin>>fi[a][b];
        for(int a=0; a<n-1; a++) if(fi[a][m-1]=='R') an++;
        for(int a=0; a<m-1; a++) if(fi[n-1][a]=='D') an++;
        cout<<an<<"\n";
    }
}