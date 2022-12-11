#include<bits/stdc++.h>
using namespace std;
const int N=5050,M=2e8+10,K=1e8;
int n,a[N],st[N],tp,ans[N];bool vis[M];
int main(){
    scanf("%d",&n);
    for(int i=1,x,y;i<=n;i++){
        scanf("%d",&x);y=x>0?1:-1;x=abs(x);
        for(int j=2;j*j<=x;j++)
            if(x%j==0){
                int num=0;
                while(x%j==0)x/=j,num++;
                if(num&1)y*=j;
            }
        if(x!=1)y*=x;a[i]=y;
    }
    for(int i=1;i<=n;i++){
        int now=0;
        for(int j=i;j<=n;j++){
            if(a[j]&&!vis[a[j]+K])vis[a[j]+K]=1,st[++tp]=a[j],now++;
            ans[max(now,1)]++;
        }
        while(tp)vis[st[tp--]+K]=0;
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}