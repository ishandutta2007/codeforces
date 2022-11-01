#include<bits/stdc++.h>
using namespace std;

int f[101],nf[101],a[4];

void mian(){
    cin>>a[1]>>a[2]>>a[3];
    memset(f,0,sizeof(f));
    f[50]=1;
    for(int i=1;i<=3;i++){
        memset(nf,0,sizeof(nf));
        for(int l=a[i]&1;l<=min(a[i],3);l+=2){
            int len=l*i;
            for(int j=len;j<=100;j++)nf[j-len]|=f[j];
            for(int j=0;j<=100-len;j++)nf[j+len]|=f[j];
        }
        swap(f,nf);
    }
    int ans=50;
    for(int i=0;i<=100;i++)if(f[i])ans=min(ans,abs(50-i));
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