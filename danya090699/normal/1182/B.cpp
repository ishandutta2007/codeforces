#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int h, w;
    cin>>h>>w;
    char fi[h][w+1];
    int go[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, fo=0, sum, tot=0;
    for(int a=0; a<h; a++) scanf("%s", fi[a]);
    for(int a=0; a<h; a++)
    {
        for(int b=0; b<w; b++)
        {
            if(fi[a][b]=='*')
            {
                tot++;

                int su=1, ok=0;
                for(int i=0; i<4; i++)
                {
                    int r=a+go[i][0], c=b+go[i][1], q=0;
                    while(r>=0 and r<h and c>=0 and c<w)
                    {
                        if(fi[r][c]=='*') q++, r+=go[i][0], c+=go[i][1];
                        else break;
                    }
                    su+=q;
                    if(q) ok++;
                }
                if(ok==4) fo++, sum=su;
            }
        }
    }
    if(fo==1 and tot==sum) cout<<"YES";
    else cout<<"NO";
}