#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    cin>>n>>m;
    int ar[n][m], suf[n][m];
    for(int a=0; a<n; a++) for(int b=0; b<m; b++) cin>>ar[a][b];
    for(int a=0; a<m; a++) suf[n-1][a]=1;
    for(int a=n-2; a>=0; a--)
    {
        for(int b=0; b<m; b++)
        {
            if(ar[a][b]<=ar[a+1][b]) suf[a][b]=suf[a+1][b]+1;
            else suf[a][b]=1;
        }
    }
    int an[n];
    for(int a=0; a<n; a++)
    {
        an[a]=0;
        for(int b=0; b<m; b++) an[a]=max(an[a], a+suf[a][b]-1);
    }
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int l, r;
        cin>>l>>r;
        l--, r--;
        if(r>an[l]) cout<<"No";
        else cout<<"Yes";
        cout<<"\n";
    }
}