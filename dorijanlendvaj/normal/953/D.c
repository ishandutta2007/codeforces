#include <stdio.h>

int x,y,mac;
char h[11][11];
int conv[6][8]={
{3,3,0,4,4,0,3,3},
{3,3,0,4,4,0,3,3},
{2,2,0,3,3,0,2,2},
{2,2,0,3,3,0,2,2},
{1,1,0,2,2,0,1,1},
{1,1,0,2,2,0,1,1}
};

int max(int a,int b)
{
    if (a>b) return a;
    return b;
}

int main()
{
    for (int i=0;i<6;++i) scanf("%s",&h[i]);
    for (int i=0;i<6;++i) for (int j=0;j<8;++j) {
        if (h[i][j]!='.') continue;
        mac=max(mac,conv[i][j]);
    }
    for (int i=0;i<6;++i) for (int j=0;j<8;++j) {
        if (h[i][j]!='.') continue;
        if (conv[i][j]==mac)
        {
            h[i][j]='P';
            for (int k=0;k<6;++k)
            {
                for (int l=0;l<8;++l) printf("%c",h[k][l]);
                printf("\n");
            }
            return 0;
        }
    }
}