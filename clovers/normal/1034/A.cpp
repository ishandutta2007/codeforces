#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const int M=15000001;
int n,a[N];
int gcd(int x,int y){
    if(!y) return x;
    return gcd(y,x%y);
}
int prime[M/10],tot=0,t[M];
bool bl[M];
void init(){
    for(int i=2;i<M;i++) bl[i]=1;
    for(int i=2;i<M;i++){
        if(bl[i]) prime[++tot]=i;
        for(int j=1;j<=tot;j++){
            if(1ll*prime[j]*i>M) break;
            bl[prime[j]*i]=0;
            if(i%prime[j]==0) break;
        }
    }
}

int main(){
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int g=a[1];
    for(int i=2;i<=n;i++){
        g=gcd(g,a[i]);
    }
    for(int i=1;i<=n;i++) a[i]/=g;
    for(int i=1;i<=n;i++){
        int tmp=a[i];
        for(int j=1;prime[j]*prime[j]<=tmp;j++){
            if(tmp%prime[j]==0){
                t[prime[j]]++;
                while(tmp%prime[j]==0) tmp/=prime[j];
            }
        }
        if(tmp>1) t[tmp]++;
    }   
    int ans=n;
    for(int i=2;i<M;i++) ans=min(ans,n-t[i]);
    if(ans==n) puts("-1");
    else printf("%d\n",ans);
    return 0;
}