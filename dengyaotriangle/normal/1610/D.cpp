#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int mdn=1000000007;
const int maxn=200005;

int n;
int a[maxn];

int pw2(int u){
    int ret=1;
    while(u--)ret=ret*2%mdn;
    return ret;
}

const int maxl=32;
int w[maxl];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int cnt=0;
        while(~a[i]&1)cnt++,a[i]>>=1;
        w[cnt]++;
    }
    int ans=0;
    int sdpx=1;
    for(int i=maxl-1;i>=1;i--){
        int u=pw2(w[i]);
        if(w[i])ans=(ans+(pw2(w[i]-1)-1)*(long long)sdpx)%mdn;
        sdpx=sdpx*(long long)u%mdn;
    }
    ans=(ans+(pw2(w[0])-1)*(long long)sdpx)%mdn;
    cout<<ans;
    return 0;
}