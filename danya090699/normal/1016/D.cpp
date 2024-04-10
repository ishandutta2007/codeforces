#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int an[n][m];
    int su=0, su2=0, ar[n], ar2[m];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        su^=ar[a];
    }
    for(int a=0; a<m; a++)
    {
        cin>>ar2[a];
        su2^=ar2[a];
    }
    if(su==su2)
    {
        cout<<"YES\n";
        int an[n][m];
        for(int a=0; a<m-1; a++)
        {
            an[0][a]=ar2[a];
            ar[0]^=ar2[a];
            for(int b=1; b<n; b++) an[b][a]=0;
        }
        for(int a=0; a<n; a++) an[a][m-1]=ar[a];
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++) cout<<an[a][b]<<" ";
            cout<<"\n";
        }
    }
    else cout<<"NO";
}