#include<stdio.h>
#include<vector>
#include<algorithm>
#define SIZE 100001
using namespace std;
int bfs[SIZE],dp[SIZE];
bool used[SIZE];
struct data{
    int y,v;
};
vector<data>Map[SIZE];
main(){
    int i,j,k,n,x,y,v,ma=0;
    long long an=0;
    scanf("%d",&n);
    n--;
    while(n--){
        scanf("%d%d%d",&x,&y,&v);
        Map[x].push_back((data){y,v});
        Map[y].push_back((data){x,v});
        an+=v;
    }
    bfs[0]=1;
    used[1]=1;
    for(i=0,j=1;i<j;i++){
        ma=max(ma,dp[i]);
        for(k=0;k<Map[bfs[i]].size();k++){
            if(!used[Map[bfs[i]][k].y]){
                used[Map[bfs[i]][k].y]=1;
                bfs[j]=Map[bfs[i]][k].y;
                dp[j]=dp[i]+Map[bfs[i]][k].v;
                j++;
            }
        }
    }
    printf("%I64d\n",an*2-ma);
}