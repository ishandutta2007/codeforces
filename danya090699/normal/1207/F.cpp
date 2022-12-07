#include <bits/stdc++.h>
using namespace std;
const int sq=700, sz=5e5+10;
int ar[sz], an[sq][sq];
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int ty, x, y;
        scanf("%d%d%d", &ty, &x, &y);
        if(ty==1)
        {
            ar[x]+=y;
            for(int b=1; b<sq; b++) an[b][x%b]+=y;
        }
        else
        {
            if(x<sq) printf("%d\n", an[x][y]);
            else
            {
                int cu=0;
                for(int b=y; b<sz; b+=x) cu+=ar[b];
                printf("%d\n", cu);
            }
        }
    }
}