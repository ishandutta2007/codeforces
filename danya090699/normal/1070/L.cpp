#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, m;
        cin>>n>>m;
        bitset <sz> ma[n];
        int ch[n], an[n];
        for(int a=0; a<n; a++) ch[a]=0, an[a]=0;
        for(int a=0; a<m; a++)
        {
            int u, v;
            cin>>u>>v;
            u--, v--;
            ma[u][v]=1, ma[v][u]=1, ch[u]^=1, ch[v]^=1;
        }
        bool fo=0;
        for(int a=0; a<n; a++)
        {
            if(ch[a])
            {
                ma[a][a]=1, ma[a][n]=1, fo=1;
            }
        }
        if(fo)
        {
            cout<<2<<"\n";
            int q=0;
            for(int a=0; a<n; a++)
            {
                int fo=-1;
                for(int b=q; b<n; b++) if(ma[b][a]) fo=b;
                if(fo!=-1)
                {
                    swap(ma[q], ma[fo]);
                    for(int b=q+1; b<n; b++) if(ma[b][a]) ma[b]^=ma[q];
                    q++;
                }
            }
            int yk=n;
            for(int a=n-1; a>=0; a--)
            {
                for(int b=n-1; b>=0; b--)
                {
                    if(ma[a][b])
                    {
                        if(b<yk) an[b]=ma[a][n], ma[a][n]=0, yk=b;
                        else if(an[b])
                        {
                            if(ma[a][n]) ma[a][n]=0;
                            else ma[a][n]=1;
                        }
                    }
                }
            }
        }
        else cout<<1<<"\n";
        for(int a=0; a<n; a++) cout<<an[a]+1<<" ";
        cout<<"\n";
    }
}