#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n][n];
        for(int a=0; a<n; a++) for(int b=0; b<n; b++) ar[a][b]=0;
        for(int a=0; a<n; a++)
        {
            for(int b=a-1; b<=a+1; b++)
            {
                if(b>=0 and b<n) ar[a][b]=1;
            }
            for(int b=0; b<n; b++) cout<<ar[a][b]<<" ";
            cout<<"\n";
        }
    }
}