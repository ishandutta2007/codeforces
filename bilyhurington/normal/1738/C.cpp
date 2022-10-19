#include<bits/stdc++.h>
using namespace std;
int T,n,cnt[2];
bool f[110][110][2];
void solve(){
    cnt[0]=cnt[1]=0;
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);
        x=(x%2+2)%2;
        cnt[x]++;
    }
    if(f[cnt[0]][cnt[1]][0]) puts("Alice");
    else puts("Bob");
}
const int N=100;
int main(){
    f[0][0][0]=1;f[0][0][1]=0;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(!i&&!j) continue;
            for(int k=0;k<2;k++){
                f[i][j][k]=0;
                if(i>0) f[i][j][k]|=!f[i-1][j][1^(j&1)^k];
                if(j>0) f[i][j][k]|=!f[i][j-1][1^(j&1)^k];
                // printf("%d %d %d %d\n",i,j,k,(int)f[i][j][k]);
            }
        }
    }
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}