#include<stdio.h>
#include<string.h>
#define SIZE 512
char s[SIZE][SIZE];
int used[SIZE][SIZE],cnt,n,m;
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,1,-1};
bool Out(int x,int y){
    if(x<0||y<0||x>=n||y>=m)return 1;
    return 0;
}
int dfs(int x,int y){
    int i;
    if(Out(x,y))return 0;
    if(s[x][y]=='0'||used[x][y])return 0;
    used[x][y]=cnt;
    int an=1;
    for(i=0;i<8;i++)
        an+=dfs(x+dx[i],y+dy[i]);
    return an;
}
bool Test(int type,int x,int y,int len){
    int i;
    if(len>=n||len>=m)return 0;
    switch(type){
        case 0:
        for(i=0;i<=len;i++){
            if(s[x][y+i]!='1')return 0;
            if(s[x+i][y]!='1')return 0;
            if(s[x+len][y+i]!='1')return 0;
            if(s[x+i][y+len]!='1')return 0;
        }
        return 1;
        case 1:
        for(i=0;i<=len;i++){
            if(s[x+i][y+i]!='1')return 0;
            if(s[x+i][y-i]!='1')return 0;
            if(s[x+i+len][y-len+i]!='1')return 0;
            if(s[x+i+len][y+len-i]!='1')return 0;
        }
            return 1;
    }
}
main(){
    int T,an,i,j;
    scanf("%d",&T);
    while(T--){
        an=0;
        cnt=0;
        scanf("%d%d",&n,&m);
        memset(s,0,sizeof(s));
        for(i=0;i<n;i++)scanf("%s",s[i]);
        memset(used,0,sizeof(used));
        for(i=0;i<n;i++)
            for(j=0;j<m;j++){
                if(s[i][j]=='1'&&!used[i][j]){
                    cnt++;
                    int num=dfs(i,j);
                    if(num%4)continue;
                    if(s[i][j+1]=='1'){
                        if(Test(0,i,j,num/4))an++;
                    }
                    else{
                        if(Test(1,i,j,num/4))an++;
                    }
                }
            }
        printf("%d\n",an);
    }
}