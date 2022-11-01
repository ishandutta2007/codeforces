#include<bits/stdc++.h>
using namespace std;

void kmp(char *s,int *nxt,int len){
    nxt[1]=0;
    int k=0;
    for(int i=2;i<=len;i++){
        while(k&&s[k+1]!=s[i])k=nxt[k];
        if(s[k+1]==s[i])k++;
        nxt[i]=k;
    }
}

typedef long long ll;
const int mod=1e9+7;

int n,m,f[205][205][105],nxt[205],ans;
char s[205];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s+1;
    n*=2;
    m=strlen(s+1);
    kmp(s,nxt,m);
    f[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<=n/2;k++){
                int nj=j;
                while(nj&&s[nj+1]!='(')nj=nxt[nj];
                nj+=s[nj+1]=='(';
                f[i][nj][k+1]=(f[i][nj][k+1]+f[i-1][j][k])%mod;
                nj=j;
                while(nj&&s[nj+1]!=')')nj=nxt[nj];
                nj+=s[nj+1]==')';
                f[i][nj][k-1]=(f[i][nj][k-1]+f[i-1][j][k])%mod;
            }
        }
        for(int k=0;k<=n/2;k++){
            f[i][m][k+1]=(f[i][m][k+1]+f[i-1][m][k])%mod;
            if(k)f[i][m][k-1]=(f[i][m][k-1]+f[i-1][m][k])%mod;
        }
    }
    cout<<f[n][m][0];

    return 0;
}