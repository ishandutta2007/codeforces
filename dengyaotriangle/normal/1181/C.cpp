#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;

const int maxn=1005;

int n,m;
char x[maxn][maxn];
int sm[maxn][maxn];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>(x[i]+1);
    }
    for(int i=1;i<=m;i++) sm[1][i]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i][j]==x[i-1][j]){
                sm[i][j]=sm[i-1][j]+1;
            }else sm[i][j]=1;
        }
    }
    long long ans=0;
    for(int l=1;l*3<=n;l++){
        for(int i=l*3;i<=n;i++){
            int cs=0;
            for(int j=1;j<=m;j++){
                if(sm[i-l][j]==l&&sm[i-l-l][j]>=l&&sm[i][j]==l){
                    if(x[i][j]==x[i][j-1]&&x[i-l][j]==x[i-l][j-1]&&x[i-l-l][j]==x[i-l-l][j-1]){
                        cs++;
                    }else{
                        ans+=(cs*(cs+1))>>1;
                        cs=1;
                    }
                }else{
                    ans+=(cs*(cs+1))>>1;
                    cs=0;
                }
            }
            ans+=(cs*(cs+1))>>1;
        }
    }
    cout<<ans;
    return 0;
}//lmyakioi