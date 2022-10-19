#include<bits/stdc++.h>
using namespace std;
int T,n,a[110],b[110];
bool f[20010],g[20010];
void solve(){
    scanf("%d",&n);int sum=0;int N=100*n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
    for(int i=1;i<=n;i++) scanf("%d",&b[i]),sum+=b[i];
    memset(f,0,sizeof(f));f[0]=1;
    for(int i=1;i<=n;i++){
        memcpy(g,f,sizeof(f));
        memset(f,0,sizeof(f));
        for(int j=0;j<=N;j++){
            f[j+a[i]]|=g[j];
            f[j+b[i]]|=g[j];
        }
    }int minn=2e9;
    for(int i=0;i<=N;i++){
        if(!f[i]) continue;
        minn=min(minn,i*i+(sum-i)*(sum-i));
    }
    for(int i=1;i<=n;i++) minn+=(n-2)*a[i]*a[i];
    for(int i=1;i<=n;i++) minn+=(n-2)*b[i]*b[i];
    printf("%d\n",minn);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}