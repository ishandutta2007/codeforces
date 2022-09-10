#include<cstdio>
char s[222][222];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        int ker=0;
        for(int k=0;k<4;k++)
            if(s[i+dx[k]][j+dy[k]]=='o')ker^=1;
        if(ker)return 0*puts("NO");
    }
    puts("YES");
    return 0;
}