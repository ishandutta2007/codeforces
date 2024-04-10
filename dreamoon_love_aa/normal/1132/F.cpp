#include <stdio.h>
#include <string.h>

const int N = 501;
int color[N], len[N];
unsigned short dp[N][N][N];
int ss[N][N];
int last[N];
int cnt=0;

/*unsigned short */int dfs(int i,int j,int k){
    int start, r, x, v;
    if(i>j) return 0;
//  if(i==j)
//      return (len[i]+k)*(len[i]+k);
    if(dp[i][j][k])
        return dp[i][j][k];
    ++cnt;
    if(/*next[color[j]][i-1] >=j*/ last[j] < i){
        dp[i][j][k] = dfs(i, j-1, 0) + 1;
        return dp[i][j][k];
    }

    if(k){
        /*for(x=k-1;x>=0;x--)
            if(dp[i][j][x])
                break;
        if(x<0) {dfs(i, j, 0); x=0;}*/
        dfs(i, j, k-1);
        start = ss[i][j];
        v = start;
//      start = s[i][j][x];
//      s[i][j][k] = s[i][j][x];
    }else{
        start = i/* next[color[j]][i-1]*/;
//      s[i][j][k] = start;
        ss[i][j] = start;
        v =start;
    }
    dp[i][j][k] = dfs(i, j-1, 0) + 1;
//  s[i][j][k] = ;
    for(x=last[j];x>=start;x=last[x]){
//      if(color[x] == color[j]){
            r = dfs(i, x, len[j] + k) + dfs(x+1, j-1, 0);
            if(dp[i][j][k] >= r){
                dp[i][j][k] = r;
            //  s[i][j][k] = x;
                v = x;
            }
//      }
    }
    ss[i][j] = v;
    //s[i][j][k] = v;
    return dp[i][j][k];
}
char input[N+2];
int main(void)
{
    int n, i, it=1;
    scanf("%d",&n);
    scanf("%s",input+1);
    {
        for(i=1;i<=n;i++){
            color[i]=input[it++]-'a'+1;
            if(color[i]==color[i-1])
                ++len[--i], --n;
            else
                len[i] = 1;
        }
        memset(dp, 0, sizeof(dp));
        //memset(s, 0, sizeof(s));
        for(i=1;i<=n;i++){
            dp[i][i][0] = 1;
        //  s[i][i][0] = i;
        }
        for(i=1;i<=n;i++){
            last[i] = -1;
            for(int j=i-1;j>0;j--)
                if(color[i]==color[j]){
                    last[i] = j;
                    break;
                }
        }
        cnt=0;
        printf("%d\n",dfs(1, n, 0));
        //printf("Case %d: %d\n",++cs, dfs(1, n, 0));
        //printf("[cnt = %d]\n",cnt);
    }
    return 0;
}