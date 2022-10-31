#include <cstdio>
int main(){
    int n, sx, sy, ex, ey, i;
    char s[100010];
    scanf("%d%d%d%d%d%s", &n, &sx, &sy, &ex, &ey, s);
    for(i = 0; s[i] && (sx!=ex||sy!=ey); ++i)
        switch(s[i]){
            case 'N': if(ey > sy)sy++;break;
            case 'S': if(ey < sy)sy--;break;
            case 'W': if(ex < sx)sx--;break;
            case 'E': if(ex > sx)sx++;break;
        }
    if(sx!=ex||sy!=ey)i=-1;
    printf("%d\n", i);
    return 0;
}