#include<bits/stdc++.h>
using namespace std;

int n;

void smol(){
    static int g[6],ans[4],d[6];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=n-1;j>=0;j--)g[i]=g[i]<<1|s[j]=='1';
    }
    for(int s=0;s<1<<n;s++){
        int c=__builtin_popcount(s);
        if(c*2>n)continue;
        for(int i=0;i<n;i++){
            d[i]=(s>>i&1?(1<<n)-1:0)^g[i];
            for(int j=0;j<n;j++)if(s>>j&1)d[i]^=1<<j;
            d[i]|=1<<i;
        }
        for(int k=0;k<n;k++)for(int i=0;i<n;i++)if(d[i]>>k&1)d[i]|=d[k];
        bool f=d[0]==(1<<n)-1;
        for(int i=1;i<n;i++)f&=d[i]&1;
        ans[c]+=f;
    }
    for(int i=0,p=1;i*2<=n;i++,p*=i)if(ans[i]){
        cout<<i<<' '<<ans[i]*p<<'\n';
        return;
    }
    cout<<"-1\n";
}

void normu(){
    static int d[2000],a[2000],g[2000][2000];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++)if(s[j]=='1'){
            d[i]++;
            g[i][j]=1;
        }
    }
    auto chk=[&](int x){
        memcpy(a,d,n*sizeof(int));
        if(x!=-1){
            for(int i=0;i<n;i++)a[i]+=g[x][i]?1:-1;
            a[x]=n-1-d[x];
        }
        sort(a,a+n);
        bool f=1;
        for(int i=0,s=0;i+1<n;i++)f&=(s+=a[i])!=i*(i+1)/2;
        return f;
    };
    if(chk(-1)){
        cout<<"0 1\n";
        return;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=chk(i);
    }
    cout<<"1 "<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    if(n<=6){
        smol();
    }else{
        normu();
    }

    return 0;
}