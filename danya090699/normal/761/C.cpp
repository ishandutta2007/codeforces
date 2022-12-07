//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, inf=1e8;
    int ans=inf;
    cin>>n>>m;
    string s[n];
    for(int a=0; a<n; a++) cin>>s[a];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            for(int c=0; c<n; c++)
            {
                if(a!=b and b!=c and a!=c)
                {
                    int d1=inf, d2=inf, d3=inf;
                    for(int d=0; d<m; d++)
                    {
                        if(s[a][d]>='0' and s[a][d]<='9') d1=min(d1, min(d, m-d));
                        if(s[b][d]>='a' and s[b][b]<='z') d2=min(d2, min(d, m-d));
                        if(s[c][d]=='#' or s[c][d]=='*' or s[c][d]=='&') d3=min(d3, min(d, m-d));
                    }
                    ans=min(ans, d1+d2+d3);
                }
            }
        }
    }
    cout<<ans;
}