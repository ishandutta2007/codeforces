#include<stdio.h>

int main()
{
    int cnt, ans=20;
    char board[20][20];
    int i,j,m,n,k,ok;

    for(i=0;i<8;i++)
        scanf("%s",board[i]);

    for(i=0;i<(1<<8);i++)
        for(j=0;j<(1<<8);j++)
        {
            cnt=0;
            for(k=0;k<8;k++)
                if(i&(1<<k))
                    cnt++;

            for(k=0;k<8;k++)
                if(j&(1<<k))
                    cnt++;

            ok = 1;
            for(m=0;m<8;m++)
                for(n=0;n<8;n++)
                    if( (board[m][n]=='B' && ((i&(1<<m)) || (j&(1<<n))) || (board[m][n]=='W' && !(i&(1<<m)) && !(j&(1<<n))) )) ;
                    else ok = 0;

            if(ok && ans > cnt) ans = cnt;
        }

    printf("%d\n",ans);

    return 0;
}