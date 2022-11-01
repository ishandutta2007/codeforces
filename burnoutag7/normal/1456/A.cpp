#include<bits/stdc++.h>
using namespace std;

int n,p,k,suf[200005],x,y,ans;
char a[100005];

void mian(){
    cin>>n>>p>>k>>a+1>>x>>y;
    ans=2e9;
    for(int i=1;i<=k;i++)suf[n+i]=0;
    for(int i=n;i>=p;i--){
        suf[i]=suf[i+k]+(a[i]=='0')*x;
        ans=min(ans,y*(i-p)+suf[i]);
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