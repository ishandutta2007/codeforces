#include <bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    if(n<3) cout<<-1;
    else
    {
        int an[n][n], nu=1;
        for(int a=3; a<n; a++)
        {
            if(a&1)
            {
                for(int b=0; b<=a; b++) an[a][b]=nu++;
                for(int b=a-1; b>=0; b--) an[b][a]=nu++;
            }
            else
            {
                for(int b=0; b<=a; b++) an[b][a]=nu++;
                for(int b=a-1; b>=0; b--) an[a][b]=nu++;
            }
        }
        an[0][0]=nu+0;
        an[0][1]=nu+1;
        an[0][2]=nu+3;
        an[1][0]=nu+4;
        an[1][1]=nu+2;
        an[1][2]=nu+7;
        an[2][0]=nu+8;
        an[2][1]=nu+5;
        an[2][2]=nu+6;

        for(int a=0; a<n; a++)
        {
            for(int b=0; b<n; b++) printf("%d ", an[a][b]);
            printf("\n");
        }
    }
}