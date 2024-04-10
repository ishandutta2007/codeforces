#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int r, c, k, q=0;
        cin>>r>>c>>k;
        char fi[r][c];
        for(int a=0; a<r; a++)
        {
            for(int b=0; b<c; b++)
            {
                cin>>fi[a][b];
                if(fi[a][b]=='R') q++;
            }
        }
        int cu=0, nu=0;
        int an[r][c];
        for(int a=0; a<r; a++)
        {
            if(a&1)
            {
                for(int b=0; b<c; b++)
                {
                    if(fi[a][b]=='R')
                    {
                        if(q/k+(nu<q%k)==cu) cu=0, nu++;
                        cu++;
                    }
                    an[a][b]=nu;
                }
            }
            else
            {
                for(int b=c-1; b>=0; b--)
                {
                    if(fi[a][b]=='R')
                    {
                        if(q/k+(nu<q%k)==cu) cu=0, nu++;
                        cu++;
                    }
                    an[a][b]=nu;
                }
            }
        }
        for(int a=0; a<r; a++)
        {
            for(int b=0; b<c; b++)
            {
                char sy;
                if(an[a][b]<26) sy='a'+an[a][b];
                else if(an[a][b]<52) sy='A'+(an[a][b]-26);
                else sy='0'+(an[a][b]-52);
                cout<<sy;
            }
            cout<<"\n";
        }
    }
}