#include<bits/stdc++.h>
using namespace std;

int n,m,ans,a[100005],b[100005];

void mian(){
    cin>>n>>m;
    memset(b,0,m<<2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]%m]++;
    }
    ans=(bool)b[0];
    for(int i=1;i<=m-1>>1;i++){
        if(min(b[i],b[m-i])){
            ans+=max(max(b[i],b[m-i])-min(b[i],b[m-i]),1);
        }else{
            ans+=max(b[i],b[m-i]);
        }
    }
    if(m&1^1)ans+=(bool)b[m>>1];
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