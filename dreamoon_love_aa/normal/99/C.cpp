#include<stdio.h>
#include<string.h>
int tran[24][6]={
        {0,1,2,3,4,5},
        {0,2,3,4,1,5},
        {0,3,4,1,2,5},
        {0,4,1,2,3,5},
        {1,2,0,4,5,3},
        {1,0,4,5,2,3},
        {1,4,5,2,0,3},
        {1,5,2,0,4,3},
        {2,5,3,0,1,4},
        {2,3,0,1,5,4},
        {2,0,1,5,3,4},
        {2,1,5,3,0,4},
        {3,2,5,4,0,1},
        {3,5,4,0,2,1},
        {3,4,0,2,5,1},
        {3,0,2,5,4,1},
        {4,0,3,5,1,2},
        {4,3,5,1,0,2},
        {4,5,1,0,3,2},
        {4,1,0,3,5,2},
        {5,4,3,2,1,0},
        {5,3,2,1,4,0},
        {5,2,1,4,3,0},
        {5,1,4,3,2,0},
};
struct data{
    char d[8];
    bool operator==(data b)const{
        int i,j;
        for(j=0;j<24;j++){
            for(i=0;i<6;i++)
                if(d[i]!=b.d[tran[j][i]])break;
            if(i==6)return 1;
        }
        return 0;
    }
    bool operator!=(data b)const{return !((*this)==b);}
}a[10000];
int an,used[6];
char tmp[8];
void dfs(int x,char s[]){
    if(x==6){
        int i;
        strcpy(a[an].d,tmp);
        for(i=0;i<an;i++)
            if(a[an]==a[i])break;
        if(i==an)an++;
        return;
    }
    for(int i=0;i<6;i++){
        if(used[i])continue;
        used[i]=1;
        tmp[x]=s[i];
        dfs(x+1,s);
        used[i]=0;
    }
}
main(){
    char s[8];
    gets(s);
    dfs(0,s);
    printf("%d\n",an);
    /*
    for(int i=0;i<an;i++,puts(""))
        for(int j=0;j<6;j++)
        printf("%c",a[i].d[j]);
    */
}