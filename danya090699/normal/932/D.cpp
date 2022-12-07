#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=4e5+10;
int up[20][sz], ma[20][sz], up2[20][sz], le[20][sz], va[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int q, last=0, cnt=1;
    cin>>q;
    va[0]=0;
    for(int a=0; a<20; a++)
    {
        up[a][0]=0, up2[a][0]=-1;
    }
    for(int a=0; a<q; a++)
    {
        int ty, r, w;
        scanf("%lld%lld%lld", &ty, &r, &w);
        r^=last, w^=last;
        r--;
        if(ty==1)
        {
            va[cnt]=w;
            up[0][cnt]=r, ma[0][cnt]=va[r];
            for(int b=1; b<20; b++)
            {
                up[b][cnt]=up[b-1][up[b-1][cnt]];
                ma[b][cnt]=max(ma[b-1][cnt], ma[b-1][up[b-1][cnt]]);
            }
            int v=cnt;
            for(int b=19; b>=0; b--)
            {
                if(ma[b][v]<w) v=up[b][v];
            }
            if(v!=0)
            {
                up2[0][cnt]=up[0][v];
                le[0][cnt]=va[up[0][v]];
            }
            else up2[0][cnt]=-1;
            for(int b=1; b<20; b++)
            {
                int ne=up2[b-1][cnt];
                if(ne!=-1) ne=up2[b-1][ne];
                if(ne!=-1)
                {
                    up2[b][cnt]=ne;
                    le[b][cnt]=le[b-1][cnt]+le[b-1][up2[b-1][cnt]];
                }
                else up2[b][cnt]=-1;
            }
            cnt++;
        }
        else
        {
            int an=0;
            if(w>=va[r])
            {
                w-=va[r], an=1;
                for(int b=19; b>=0; b--)
                {
                    int ne=up2[b][r];
                    if(ne!=-1 and le[b][r]<=w)
                    {
                        w-=le[b][r], an+=(1ll<<b), r=ne;
                    }
                }
            }
            last=an;
            printf("%lld\n", last);
        }
    }
}