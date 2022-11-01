#include<bits/stdc++.h>
using namespace std;

bool prv[505][505];
char s[505],t[1005];
int n,m;

void mian(){
    cin>>s+1>>t+1;
    n=strlen(s+1);
    m=strlen(t+1);
    memset(prv,0,sizeof(prv));
    prv[0][0]=1;
    for(int i=1;i<=n;i++){
        prv[i][0]=1;
        for(int j=i,k=m;j<=n&&k>=1&&s[j]==t[k];j++,k--){
            prv[j][m-k+1]=1;
        }
    }
    bool f=0;
    for(int i=1;i<=n;i++){
        for(int j=i,k=1;j<=n&&k<=m&&s[j]==t[k];j++,k++){
            f|=prv[j-1][m-k];
        }
    }
    cout<<(f?"YES\n":"NO\n");
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