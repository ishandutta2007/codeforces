#include<bits/stdc++.h>
using namespace std;

int n,pre[2][300005],suf[2][300005];
char s[300005];

void solve(){
    cin>>n;
    cin>>s;
    memset(pre[0],0,n+1<<2);
    memset(pre[1],0,n+1<<2);
    memset(suf[0],0,n+1<<2);
    memset(suf[1],0,n+1<<2);
    for(int i=1;i<=n;i++){
        if(s[i-1]=='L')pre[0][i]=pre[1][i-1]+1;
        if(s[i-1]=='R')pre[1][i]=pre[0][i-1]+1;
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='L')suf[1][i]=suf[0][i+1]+1;
        if(s[i]=='R')suf[0][i]=suf[1][i+1]+1;
    }
    for(int i=0;i<=n;i++){
        cout<<pre[0][i]+1+suf[0][i]<<' ';
    }
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)solve();

    return 0;
}