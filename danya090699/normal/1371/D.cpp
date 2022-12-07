#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        if(k%n==0) cout<<"0\n";
        else cout<<"2\n";
        bool an[n][n];
        for(int a=0; a<n; a++) for(int b=0; b<n; b++) an[a][b]=0;
        for(int a=0; a<k; a++)
        {
            int r=a%n, c=(r+a/n)%n;
            an[r][c]=1;
        }
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<n; b++) cout<<an[a][b];
            cout<<"\n";
        }
    }
}