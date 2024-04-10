#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
#define SIZE 200010
const int MOD =1000000007; 
map<int,int>hash;
int dp[SIZE],dp2[SIZE];
struct data{
    int x,y;
    bool operator<(data b)const{
        return y<b.y||(y==b.y&&x<b.x);
    }
    void scan(){
        scanf("%d%d",&x,&y);
        hash[x]=0;
        hash[y]=0;
    }
}a[SIZE];
int main(){
    int n,m,i,j,N;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)a[i].scan();
    if(!hash.count(0)||!hash.count(n)){
        puts("0");
        return 0;
    }
    sort(a,a+m);
    map<int,int>::iterator it;
    for(i=1,it=hash.begin();it!=hash.end();it++,i++)
        it->second=i;
    N=i;
    for(i=0;i<m;i++)
        a[i]=(data){hash[a[i].x],hash[a[i].y]};
    dp2[1]=1;
    for(i=2,j=0;i<N;i++){
        dp[i]=0;
        while(j<m&&a[j].y==i){
            dp[i]+=(dp2[i-1]-dp2[a[j].x-1])%MOD;
            dp[i]%=MOD;
            j++;
        }
        dp2[i]=(dp2[i-1]+dp[i])%MOD;
    }
    if(dp[N-1]<0)dp[N-1]+=MOD;
    printf("%d\n",dp[N-1]);
    return 0;
}