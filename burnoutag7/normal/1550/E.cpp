#include<bits/stdc++.h>
using namespace std;

int n,k,len[200005][17],nxt[200005][17],f[1<<17];
char s[200005];

bool chk(int m){
    for(int i=n;i>=1;i--){
        for(int j=0;j<k;j++){
            nxt[i][j]=len[i][j]>=m?i+m-1:nxt[i+1][j];
        }
    }
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int s=0;s<1<<k;s++)if(f[s]<n){
        for(int i=0;i<k;i++)if(s>>i&1^1){
            f[s|1<<i]=min(f[s|1<<i],nxt[f[s]+1][i]);
        }
    }
    return f[(1<<k)-1]<=n;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>s+1;
    for(int i=n;i>=1;i--){
        for(int j=0;j<k;j++){
            len[i][j]=s[i]=='?'||s[i]-'a'==j?len[i+1][j]+1:0;
        }
    }
    fill(nxt[n+1],nxt[n+1]+k,n+1);
    int l=0,r=n/k,m,res;
    while(l<=r){
        m=l+r>>1;
        if(chk(m)){
            res=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    cout<<res<<'\n';

    return 0;
}