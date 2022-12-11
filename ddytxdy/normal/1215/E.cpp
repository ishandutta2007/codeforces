#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=4e5+50,M=2e6;
int n,a[N],mx=1<<20;LL s[20],f[M],b[20][20];
int main(){
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);x--;
        for(int j=0;j<20;j++)b[x][j]+=s[j];
        s[x]++;
    }
    memset(f,0x3f,sizeof(f));f[0]=0;
    for(int i=0;i<mx-1;i++){
        for(int j=0;j<20;j++)if(!((i>>j)&1)){
            LL dat=0;
            for(int k=0;k<20;k++)
                if((i>>k)&1)dat+=b[k][j];
            f[i^(1<<j)]=min(f[i^(1<<j)],f[i]+dat);
        }
    }
    cout<<f[mx-1];
    return 0;
}