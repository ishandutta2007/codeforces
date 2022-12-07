#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    string fi[n];
    for(int a=0; a<n; a++) cin>>fi[a];
    bool ce[n][m];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            int q=0;
            if(a>0 and a+1<n and b>0 and b+1<m)
            {
                for(int da=-1; da<=1; da++)
                {
                    for(int db=-1; db<=1; db++)
                    {
                        if(!(da==0 and db==0)) if(fi[a+da][b+db]=='#') q++;
                    }
                }
            }
            if(q==8) ce[a][b]=1;
            else ce[a][b]=0;
        }
    }
    bool ok=1;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            if(fi[a][b]=='#')
            {
                bool fo=0;
                for(int da=-1; da<=1; da++)
                {
                    for(int db=-1; db<=1; db++)
                    {
                        if(!(da==0 and db==0))
                        {
                            if(a+da>0 and a+da<n and b+db>0 and b+db<m)
                            {
                                if(ce[a+da][b+db]) fo=1;
                            }
                        }
                    }
                }
                if(fo==0) ok=0;
            }
        }
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
}