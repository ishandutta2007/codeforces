#include<bits/stdc++.h>
using namespace std;
const int N=1000000,mod=1e9+7;
int q,minp[N+10],pri[N+10],ptot;
bool isp[N+10];
int f[N+10][21];
void Pre(){
    for(int i=2;i<=N;i++){
        if(!isp[i]){minp[i]=i;pri[++ptot]=i;}
        for(int j=1;j<=ptot&&i*pri[j]<=N;j++){
            isp[i*pri[j]]=1;
            minp[i*pri[j]]=pri[j];
            if(i%pri[j]==0) break;
        }
    }f[0][0]=1;
    for(int i=1;i<=20;i++) f[0][i]=2;
    for(int i=1;i<=N;i++){
        f[i][0]=f[i-1][0];
        for(int j=1;j<=20;j++){
            f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
        }
    }
}
int main(){Pre();
    scanf("%d",&q);
    while(q--){
        int x,y,lstp=0,cntp=0;
        scanf("%d %d",&x,&y);
        long long ans=1;
        while(y>1){
            if(lstp!=minp[y]){
                ans=ans*f[x][cntp]%mod;
                cntp=0;lstp=minp[y];
                // printf("%d\n",cntp);
            }cntp++;
            y/=minp[y];
        }ans=ans*f[x][cntp]%mod;
        printf("%lld\n",ans);
    }
    return 0;
}