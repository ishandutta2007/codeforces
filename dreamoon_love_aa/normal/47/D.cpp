#include<stdio.h>
int an,d[10],n,m;
char s[10][42],now[42];
bool Check(){
    int i,j,wrong;
    for(i=1;i<m;i++){
        wrong=0;
        for(j=0;j<n;j++)
            if(s[i][j]!=now[j])wrong++;
        if(wrong!=d[i])return 0;
    }
    return 1;
}
void dfs(int x,int y,char str[],int wrong){
    if(x==n){
        if(y==wrong&&Check())an++;
        return;
    }
    now[x]=str[x];
    dfs(x+1,y,str,wrong);
    if(y==wrong)return;
    now[x]=1-str[x]+'0'+'0';
    dfs(x+1,y+1,str,wrong);
}
main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)scanf("%s%d",s[i],&d[i]);
    dfs(0,0,s[0],d[0]);
    printf("%d\n",an);
}