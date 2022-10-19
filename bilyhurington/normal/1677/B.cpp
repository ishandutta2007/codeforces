#include<bits/stdc++.h>
using namespace std;
int T,n,m,sum[1000010],sum2[1000010],ans[1000010],ans2[1000010];
char s[1000010];
void solve(){
    scanf("%d %d %s",&n,&m,s+1);
    for(int i=1;i<=n*m;i++){
        ans2[i]=ans[i]=0;
        sum[i]=sum[i-1]+(s[i]=='1');
        if(i>m) sum2[i]=sum2[i-m];
        else sum2[i]=0;
        sum2[i]+=s[i]=='1';
    }
    for(int i=1;i<=n*m;i++){
        int l=max(1,i-m+1),t=sum[i]-sum[l-1];
        if(t>0) ans[i]++;
        if(sum2[i]){
            ans2[i]++;
            if(i+m<=n*m) ans2[i+m]--;
        }
    }
    for(int i=1;i<=n*m;i++){
        if(i>m) ans[i]+=ans[i-m];
        ans2[i]+=ans2[i-1];
        printf("%d ",ans[i]+ans2[i]);
    }puts("");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}