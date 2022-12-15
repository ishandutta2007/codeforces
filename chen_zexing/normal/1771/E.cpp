#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[405][405];
int u[405][405][2],d[405][405][2];
int pre[405][405][2];
int main(){
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(s[i][j]=='#') u[i][j][0]=u[i][j][1]=0;
                else if(s[i][j]=='m') u[i][j][0]=0,u[i][j][1]=u[i-1][j][0]+1;
                else u[i][j][0]=u[i-1][j][0]+1,u[i][j][1]=u[i-1][j][1]+1;
                u[i][j][1]=max(u[i][j][1],u[i][j][0]);
            }
        for(int i=n;i;i--)
            for(int j=1;j<=m;j++){
                if(s[i][j]=='#') d[i][j][0]=d[i][j][1]=0;
                else if(s[i][j]=='m') d[i][j][0]=0,d[i][j][1]=d[i+1][j][0]+1;
                else d[i][j][0]=d[i+1][j][0]+1,d[i][j][1]=d[i+1][j][1]+1;
                d[i][j][1]=max(d[i][j][1],d[i][j][0]);
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                pre[i][j][0]=pre[i][j-1][0]+(s[i][j]=='m'),pre[i][j][1]=pre[i][j-1][1]+(s[i][j]=='#');
        int ans=0;
        for(int i=2;i<n;i++)
            for(int j=2;j<m;j++)
                for(int k=j;k<m;k++){
                    if(pre[i][k][1]-pre[i][j-1][1]) continue;
                    if(pre[i][k][0]-pre[i][j-1][0]>1) continue;
                    if(pre[i][k][0]-pre[i][j-1][0]){
                        int uu=min(u[i][j-1][0]-1,u[i][k+1][0]-1),dd=min(d[i][j-1][0]-1,d[i][k+1][0]-1);
                        if(uu>=1&&dd>=1) ans=max(ans,(uu+dd)*2+2+k-j+1);
                    }
                    else{
                        if(s[i][j-1]=='m'&&s[i][k+1]=='m') continue;
                        int uu,dd;
                        if(s[i][j-1]=='m'){
                            uu=min(u[i][j-1][1]-1,u[i][k+1][0]-1),dd=min(d[i][j-1][1]-1,d[i][k+1][0]-1);
                            if(uu>=1&&dd>=1) ans=max(ans,(uu+dd)*2+2+k-j+1);
                        }
                        else if(s[i][k+1]=='m'){
                            uu=min(u[i][j-1][0]-1,u[i][k+1][1]-1),dd=min(d[i][j-1][0]-1,d[i][k+1][1]-1);
                            if(uu>=1&&dd>=1) ans=max(ans,(uu+dd)*2+2+k-j+1);
                        }
                        else{
                            uu=min(u[i][j-1][1]-1,u[i][k+1][0]-1),dd=min(d[i][j-1][0]-1,d[i][k+1][0]-1);
                            if(uu>=1&&dd>=1) ans=max(ans,(uu+dd)*2+2+k-j+1);
                            uu=min(u[i][j-1][0]-1,u[i][k+1][1]-1),dd=min(d[i][j-1][0]-1,d[i][k+1][0]-1);
                            if(uu>=1&&dd>=1) ans=max(ans,(uu+dd)*2+2+k-j+1);
                            uu=min(u[i][j-1][0]-1,u[i][k+1][0]-1),dd=min(d[i][j-1][1]-1,d[i][k+1][0]-1);
                            if(uu>=1&&dd>=1) ans=max(ans,(uu+dd)*2+2+k-j+1);
                            uu=min(u[i][j-1][0]-1,u[i][k+1][0]-1),dd=min(d[i][j-1][0]-1,d[i][k+1][1]-1);
                            if(uu>=1&&dd>=1) ans=max(ans,(uu+dd)*2+2+k-j+1);
                        }
                    }
                }
        printf("%d\n",ans);
    }
    return 0;
}