#include<bits/stdc++.h>
using namespace std;

int n,f[100005][8],a[100005];
char s[100005];

void mian(){
    cin>>n>>s+1;
    for(int i=1;i<=n;i++){
        a[i]=1<<s[i]-'0';
    }
    cin>>s+1;
    for(int i=1;i<=n;i++){
        a[i]|=1<<s[i]-'0';
    }
    memset(f[0],0xc0,sizeof(f[0]));
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        memset(f[i],0xc0,sizeof(f[i]));
        for(int j=0;j<8;j++){
            int nj=j|a[i];
            int c=0,nc=0;
            while(1<<c&j)c++;
            while(1<<nc&nj)nc++;
            f[i][nj]=max(f[i][nj],f[i-1][j]+nc-c);
        }
        f[i][0]=*max_element(f[i],f[i]+8);
    }
    cout<<*max_element(f[n],f[n]+8)<<'\n';
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