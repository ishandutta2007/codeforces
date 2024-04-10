#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int q[m];
    for(int a=0; a<m; a++) q[a]=0;
    string s[n];
    for(int a=0; a<n; a++)
    {
        cin>>s[a];
        for(int b=0; b<m; b++) if(s[a][b]=='1') q[b]++;
    }
    bool fo=0;
    for(int a=0; a<n; a++)
    {
        bool ok=1;
        for(int b=0; b<m; b++) if(s[a][b]=='1' and q[b]==1) ok=0;
        if(ok) fo=1;
    }
    if(fo) cout<<"YES";
    else cout<<"NO";
}