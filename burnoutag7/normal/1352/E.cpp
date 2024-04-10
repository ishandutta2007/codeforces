#include<bits/stdc++.h>
using namespace std;

int T,n;
int a[8005];
int pre[8005];
int spec[8005];

int main(){

    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(spec,0,sizeof(spec));
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            pre[i]=pre[i-1]+a[i];
            for(int j=0;j+1<i;j++){
                if(pre[i]-pre[j]<=n)spec[pre[i]-pre[j]]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=spec[a[i]];
        }
        cout<<ans<<endl;
    }

    return 0;
}