#include<stdio.h>
const int MOD = 1000000007;
char s[1024][1024];
int type[256][256],n,m;
int dp1[256],dp2[256];
int f(int x){
    int i,k=0;
    if(type[0][x]%2==1&&type[0][x-1]%2==1)dp2[0]=1;
    else dp2[0]=0;
    if(!(type[0][x-1]&2)||!(type[0][x]&2))k=1;
    for(i=1;i<n;i++){
        if(!(type[i][x-1]&2)||!(type[i][x]&2))k=1;
        if((type[i][x-1]&1)&&(type[i][x]&1))dp2[i]=dp2[i-1];
        else dp2[i]=0;
        if((type[i-1][x-1]&2)&&(type[i-1][x]&2)&&(type[i][x-1]&2)&&(type[i][x]&2)){
            if(i>1)dp2[i]+=dp2[i-2];
            else dp2[i]++;
            dp2[i]%=MOD;
        }
    }
    if(k==0&&n%2==0)return (dp2[n-1]+MOD-1)%MOD;
    else return dp2[n-1];
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<=(n<<2);i++)scanf("%s",s[i]);
    if(n%2==1&&m%2==1){
        puts("0");
        return 0;
    }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(s[i*4+1][j*4+2]=='O')type[i][j]=1;
            else if(s[i*4+2][j*4+1]=='O')type[i][j]=2;
            else if(s[i*4+1][j*4+1]=='O'&&s[i*4+1][j*4+3]=='O')type[i][j]=3;
            else if(s[i*4+1][j*4+1]=='O')type[i][j]=1;
            else if(s[i*4+1][j*4+3]=='O')type[i][j]=2;
            else type[i][j]=3;
        }
    for(i=0;i<n;i++)
        if(!(type[i][0]&2))break;
    if(i==n&&n%2==0)dp1[0]=1;
    for(i=1;i<m;i++){
        for(j=0;j<n;j++)
            if(!(type[j][i]&2))break;
        if(j==n&&n%2==0)dp1[i]=dp1[i-1];
        int tmp=f(i);
        if(i==1)dp1[i]=(dp1[i]+tmp)%MOD;
        else dp1[i]=(dp1[i]+(long long)tmp*dp1[i-2])%MOD;
    }
    printf("%d\n",dp1[m-1]);
    return 0;
}