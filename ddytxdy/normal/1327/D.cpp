#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,T,a[N],c[N],ans,b[N];bool vis[N];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),vis[i]=0;
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);ans=n;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;vis[i]=1;int len=1;b[0]=i;
        for(int j=a[i];j!=i;j=a[j])vis[j]=1,b[len++]=j;
        for(int j=1;j*j<=len;j++)if(len%j==0){
            for(int k=0;k<j;k++){
                int cc=c[b[k]];
                for(int l=(k+j)%len;l!=k;l=(l+j)%len)c[b[l]]^cc?cc=0:0;
                if(cc)ans=min(ans,j);
            }
            if(j*j!=len){
                int x=len/j;
                for(int k=0;k<x;k++){
                    int cc=c[b[k]];
                    for(int l=(k+x)%len;l!=k;l=(l+x)%len)c[b[l]]^cc?cc=0:0;
                    if(cc)ans=min(ans,x);
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
}