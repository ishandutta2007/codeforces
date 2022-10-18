#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1005;
int n;
int c[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i];
    long long ans=0;
    for(int i=1;i<=n;i+=2){
        long long pfx=0,mi=0;
        for(int j=i+1;j<=n;j+=2){
            long long lmin=-mi;
            long long mt=pfx+lmin;
            long long cur=0;
            if(j==i+1){
                cur=min(c[i],c[j]);
            }else cur=max(0ll,min(c[i]+1-lmin-max(0ll,-mt),c[j]+1-max(0ll,mt)));
            ans+=cur;
            pfx-=c[j];
            mi=min(mi,pfx);
            pfx+=c[j+1];
        }
    }
    cout<<ans;
    return 0;
}