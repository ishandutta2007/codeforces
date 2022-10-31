#include<stdio.h>
int n,d,dp[401][401];
const int Mid=200;
struct data{
    int x,y;
    void scan(){scanf("%d%d",&x,&y);}
}a[20];
int sqr(int x){return x*x;}
bool Go(int x,int y){
    if(sqr(x)+sqr(y)>sqr(d))return 1;
    if(dp[x+Mid][y+Mid]==1)return 1;
    if(dp[x+Mid][y+Mid]==-1)return 0;
    int i;
    for(i=0;i<n;i++){
        if(!Go(x+a[i].x,y+a[i].y)){
            dp[x+Mid][y+Mid]=1;
            return 1;
        }
    }
    dp[x+Mid][y+Mid]=-1;
    return 0;
}
main(){
    int x,y,i;
    scanf("%d%d%d%d",&x,&y,&n,&d);
    for(i=0;i<n;i++)a[i].scan();
    if(Go(x,y))puts("Anton");
    else puts("Dasha");
}