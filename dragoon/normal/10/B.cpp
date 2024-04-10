#include<stdio.h>

#define sum(a,b) ((b)+(a))*((b)-(a)+1)/2
#define ABS(A) ((A)>0?(A):(-(A)))

int mat[102][102];
int rsum[102][102];

int main()
{
    int x, yl, yr;
    int here, now;

    int n, k, rc, cc;
    int m,i,j;

    scanf("%d%d",&n,&k);

    rc = (k+1)/2;
    cc = rc;

    while(n--)
    {
        scanf("%d",&m);
        
        x=-1;
        yl=yr=0;
        now = 1000000000;

        for(i=1;i<=k;i++)
            for(j=1;j<=k-m+1;j++)
            {
                here = rsum[i][j+m-1] - rsum[i][j-1];
                if(here) continue;

                here = ABS(i-rc)*m;

                if(j>=cc)
                {
                    here += sum( j-cc, j+m-1-cc);
                }
                else if(j+m-1<=cc)
                {
                    here += sum( cc - j - m + 1, cc - j);
                }
                else
                {
                    here += sum( 0, j+m-1-cc);
                    here += sum( 0, cc - j);
                }

                if(here<now)
                {
                    now = here;
                    x = i;
                    yl = j;
                    yr = j+m-1;
                }
            }

        if(x==-1) {printf("-1\n"); continue;}

        printf("%d %d %d\n",x,yl,yr);

        for(i=yl;i<=k;i++)
        {
            if(i<=yr) mat[x][i] = 1;
            rsum[x][i]=rsum[x][i-1]+mat[x][i];

        }
    }


    return 0;
}