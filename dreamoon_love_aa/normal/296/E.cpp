#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define MOD 1000000007
long long cnt[2][51][51],step[2][51][51],C[51][51];
bool used[2][51][51];
struct data{
    int lr,x,y;
}bfs[100000];
int to(int lr,int v){
    if(lr==0)return -v;
    return v;
}
int main(){
    int i,j,k,n;
    for(i=0;i<51;i++){
        C[i][0]=1;
        for(j=1;j<=i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=MOD)C[i][j]-=MOD;
        }
    }
    int d[2]={};
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&j);
        if(j==50)d[0]++;
        else d[1]++;
    }
    bfs[0]=(data){0,d[0],d[1]};
    used[0][d[0]][d[1]]=1;
    cnt[0][d[0]][d[1]]=1;
    for(i=0,j=1;i<j;i++){
        data now=bfs[i];
        int bb[2];
        if(now.lr==0){
            bb[0]=now.x;
            bb[1]=now.y;
        }
        else{
            bb[0]=d[0]-now.x;
            bb[1]=d[1]-now.y;
        }
        for(int k1=0;k1*50<=k&&k1<=bb[0];k1++)
            for(int k2=0;k1*50+k2*100<=k&&k2<=bb[1];k2++){
                if(k1+k2==0)continue;
                if(!used[now.lr^1][now.x+to(now.lr,k1)][now.y+to(now.lr,k2)]){
                    used[now.lr^1][now.x+to(now.lr,k1)][now.y+to(now.lr,k2)]=1;
                    step[now.lr^1][now.x+to(now.lr,k1)][now.y+to(now.lr,k2)]=step[now.lr][now.x][now.y]+1;
                    bfs[j++]=(data){now.lr^1,now.x+to(now.lr,k1),now.y+to(now.lr,k2)};
                }
                if(step[now.lr][now.x][now.y]+1==step[now.lr^1][now.x+to(now.lr,k1)][now.y+to(now.lr,k2)]){
                    cnt[now.lr^1][now.x+to(now.lr,k1)][now.y+to(now.lr,k2)]+=cnt[now.lr][now.x][now.y]*C[bb[0]][k1]%MOD*C[bb[1]][k2]%MOD;
                    if(cnt[now.lr^1][now.x+to(now.lr,k1)][now.y+to(now.lr,k2)]>=MOD)cnt[now.lr^1][now.x+to(now.lr,k1)][now.y+to(now.lr,k2)]-=MOD;
                }
            }
    }
    if(used[1][0][0]==0)puts("-1\n0");
    else printf("%I64d\n%I64d\n",step[1][0][0],cnt[1][0][0]);
    return 0;
}