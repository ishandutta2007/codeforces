#include<bits/stdc++.h>
using namespace std;

int n,f[100005][8];
char s[100005];

void mian(){
    cin>>s+1;
    n=strlen(s+1);
    memset(f[0],0x3f,sizeof(f[0]));
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        memset(f[i],0x3f,sizeof(f[i]));
        int cb=s[i]-'0';
        for(int j=0;j<8;j++){
            int nj=j|1<<cb;
            int c=0,nc=0;
            while(1<<c&j)c++;
            while(1<<nc&nj)nc++;
            f[i][nj]=min(f[i][nj],f[i-1][j]+nc-c);
        }
        f[i][0]=*min_element(f[i],f[i]+8);
    }
    cout<<*min_element(f[n],f[n]+8)<<'\n';
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