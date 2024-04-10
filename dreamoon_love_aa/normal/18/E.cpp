#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char s[512][512],answer[512][2];
int change[512][4][4],letter[512][2][4],dp[512][4][4];
struct data{
    int x,y;
    bool operator<(data b)const{return x>b.x||(x==b.x&&y<b.y);}
}last[512][4][4];
void back(int x,int i,int j){
    answer[x][0]=letter[x][0][i]+'a';
    answer[x][1]=letter[x][1][j]+'a';
    if(!x)return;
    back(x-1,last[x][i][j].x,last[x][i][j].y);
}
main(){
    memset(dp,-1,sizeof(dp));
    int n,m,i,j,k,jj,kk,cnt[2][26],an=1000000000;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",s[i]);
        for(j=0;j<m;j++)s[i][j]-='a';
    }
    for(i=0;i<n;i++){
        data tmp[2][26];
        for(k=0;k<2;k++){
            for(j=0;j<26;j++)cnt[k][j]=0;
            for(j=k;j<m;j+=2)cnt[k][s[i][j]]++;
            for(j=0;j<26;j++)tmp[k][j]=(data){cnt[k][j],j};
            sort(tmp[k],tmp[k]+26);
            for(j=0;j<4;j++)letter[i][k][j]=tmp[k][j].y;
        }
        for(j=0;j<4;j++)
            for(k=0;k<4;k++){
                change[i][j][k]=m-tmp[0][j].x-tmp[1][k].x;
            }
        if(i){
            for(j=0;j<4;j++)
                for(k=0;k<4;k++)
                    for(jj=0;jj<4;jj++)
                        for(kk=0;kk<4;kk++){
                            if(dp[i-1][jj][kk]<0)continue;
                            if(letter[i][0][j]!=letter[i][1][k]
                             &&letter[i][0][j]!=letter[i-1][0][jj]
                             &&letter[i][1][k]!=letter[i-1][1][kk]
                             &&letter[i-1][0][jj]!=letter[i-1][1][kk]){
                                if(dp[i][j][k]<0||dp[i][j][k]>dp[i-1][jj][kk]+change[i][j][k]){
                                    dp[i][j][k]=dp[i-1][jj][kk]+change[i][j][k];
                                    last[i][j][k]=(data){jj,kk};
                                }
                            }
                        }
        }
        else{
            for(j=0;j<4;j++)
                for(k=0;k<4;k++)
                    if(letter[i][0][j]!=letter[i][1][k]){
                        dp[0][j][k]=change[0][j][k];
                    }
        }
    }
    for(i=0;i<4;i++)
        for(j=0;j<4;j++){
            if(dp[n-1][i][j]!=-1&&an>dp[n-1][i][j])an=dp[n-1][i][j],jj=i,kk=j;
        }
    back(n-1,jj,kk);
    printf("%d\n",an);
    for(i=0;i<n;i++,puts("")){
        for(j=0;j<m;j++)printf("%c",answer[i][j&1]);
    }
}