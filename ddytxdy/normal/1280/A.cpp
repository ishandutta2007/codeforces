#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50,mod=1e9+7;
int t,x,now,ans;char s[N];bool flag;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&x,s+1);
        ans=now=strlen(s+1);flag=now>=x;
        for(int i=1;i<=x;i++){
            int y=s[i]-'0'-1,len=now-i;ans=(ans+1ll*y*(ans-i))%mod;
            if(!flag){
                int lim=min(x-now,len*y);
                for(int j=1;j<=lim;j++)s[++now]=s[(j-1)%len+1+i];
            }
            if(now>=x)flag=1;
        }
        printf("%d\n",(ans+mod)%mod);
    }
    return 0;
}