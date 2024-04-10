#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <int> sp[n+1];
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        sp[x].push_back(a);
    }
    char an[n+1][n+1];
    for(int a=0; a<=n; a++)
    {
        for(int b=0; b<n; b++) an[a][b]='0';
        an[a][n]=0;
    }
    int l=0, r=n-1;
    for(int a=n; a>=1; a--)
    {
        if(sp[a].size()==1)
        {
            for(int b=r; b>r-a; b--) an[b][sp[a][0]]='1';
            r--;
        }
        if(sp[a].size()>1)
        {
            int lef=a-(sp[a].size()-1);
            for(int b=0; b<l; b++)
            {
                if(lef>0)
                {
                    for(int c=0; c<sp[a].size(); c++) an[b][sp[a][c]]='1';
                    lef--;
                }
            }
            for(int b=0; b<sp[a].size(); b++)
            {
                for(int c=0; c<min(a, int(sp[a].size())-1); c++)
                {
                    int i=sp[a][(b+c)%sp[a].size()];
                    an[l][i]='1';
                }
                l++;
            }
            for(int b=l; b<=n; b++)
            {
                if(lef>0)
                {
                    for(int c=0; c<sp[a].size(); c++) an[b][sp[a][c]]='1';
                    lef--;
                }
            }
        }
    }
    cout<<n+1<<"\n";
    for(int a=0; a<=n; a++) printf("%s\n", an[a]);
}