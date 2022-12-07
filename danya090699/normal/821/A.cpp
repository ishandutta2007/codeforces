#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, pos=1;
    cin>>n;
    int ar[n][n];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++) cin>>ar[a][b];
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            int fo=0;
            if(ar[a][b]==1) fo=1;
            for(int c=0; c<n; c++)
            {
                for(int d=0; d<n; d++) if(ar[a][b]==ar[a][c]+ar[d][b]) fo=1;
            }
            if(fo==0) pos=0;
        }
    }
    if(pos) cout<<"Yes";
    else cout<<"No";
}