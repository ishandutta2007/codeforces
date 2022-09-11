#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int two[20],v[5][5],dp[1000000];
char Map[5][99];
vector<int>step;
bool Out(int x,int y){
    if(x<0||y<0||x>=5||y>=5)return 1;
    if(x-y>2||y-x>2)return 1;
    return 0;
}
bool Go(int x){
    if(dp[x]==1)return 1;
    else if(dp[x]==-1)return 0;
    int i;
    for(i=0;i<step.size();i++){
        if((x&step[i])==step[i]){
            if(!Go(x-step[i])){
                dp[x]=1;
                return 1;
            }
        }
    }
    dp[x]=-1;
    return 0;
}
main(){
    int i,j,k,tmp;
    two[0]=1;
    for(i=1;i<20;i++)two[i]=two[i-1]*2;
    for(i=k=0;i<5;i++)
        for(j=0;j<5;j++){
            if(Out(i,j))continue;
            v[i][j]=two[k++];
        }
    for(i=0;i<5;i++)
        for(j=0;j<5;j++){
            if(Out(i,j))continue;
            for(k=tmp=0;!Out(i,j+k);k++){
                tmp+=v[i][j+k];
                step.push_back(tmp);
            }
            for(k=tmp=0;!Out(i+k,j);k++){
                tmp+=v[i+k][j];
                step.push_back(tmp);
            }
            for(k=tmp=0;!Out(i+k,j+k);k++){
                tmp+=v[i+k][j+k];
                step.push_back(tmp);
            }
        }
    for(i=0;i<5;i++){
        gets(Map[i]);
        for(j=k=0;Map[i][j];j++)
            if(Map[i][j]!=' ')Map[i][k++]=Map[i][j];
        if(i==3){
            for(j=4;j>0;j--)Map[i][j]=Map[i][j-1];
        }
        else if(i==4){
            for(j=4;j>1;j--)Map[i][j]=Map[i][j-2];
        }
    }
    for(i=tmp=0;i<5;i++)
        for(j=0;j<5;j++){
            if(Out(i,j))continue;
            if(Map[i][j]=='O')tmp+=v[i][j];
        }
    if(Go(tmp))puts("Karlsson");
    else puts("Lillebror");
}