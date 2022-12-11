#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int t,n,x,tmp[N],*cnt=tmp+100000,now,ans;char s[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%s",&n,&x,s+1);now=ans=0;
        for(int i=1;i<=n;i++)now+=s[i]=='0'?1:-1,cnt[now]++;
        if(!now){
            if(x>=-n&&x<=n&&cnt[x]||!x)puts("-1");
            else puts("0");
        }
        else{
            for(int i=-n;i<=n;i++)if((i-x)%now==0){
                if(now>0&&i<=x)ans+=cnt[i];
                if(now<0&&i>=x)ans+=cnt[i];
            }
            ans+=!x;
            cout<<ans<<endl;
        } 
        for(int i=-n;i<=n;i++)cnt[i]=0;
    }
    return 0;
}