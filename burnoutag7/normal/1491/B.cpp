#include<bits/stdc++.h>
using namespace std;

int n,u,v,a[105];

void mian(){
    cin>>n>>u>>v;
    int ans=2e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&abs(a[i]-a[i-1])>1)ans=0;
    }
    for(int i=1;i<=n;i++){
        if(i>1&&a[i-1]!=a[i])ans=min(ans,u);
        if(i<n&&a[i+1]!=a[i])ans=min(ans,u);
        if(a[i]>2)ans=min(ans,v<<1);
        if(a[i]<999999)ans=min(ans,v<<1);
        if(i>1&&(a[i]>1||a[i]<1000000)&&a[i-1]==a[i])ans=min(ans,u+v);
        if(i<n&&(a[i]>1||a[i]<1000000)&&a[i+1]==a[i])ans=min(ans,u+v);
        if(a[i]>1&&(i>1&&a[i-1]>a[i]||i<n&&a[i+1]>a[i]))ans=min(ans,v);
        if(a[i]<1000000&&(i>1&&a[i-1]<a[i]||i<n&&a[i+1]<a[i]))ans=min(ans,v);
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}