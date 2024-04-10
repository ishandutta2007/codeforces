#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=66;
const int maxm=260;
int pt[maxn][maxn];
int c[maxm];
int n,m;

int a[maxm][maxm];
int x[maxm];

bool ins(){
    for(int i=1;i<=m;i++){
        if(x[i]){
            if(!a[i][i]){
                int p=x[i];
                for(int j=1;j<=m+1;j++)a[i][j]=x[j]*p%3;
                return 0;
            }else{
                for(int j=m+1;j>=i;j--)x[j]=(x[j]+a[i][j]*(3-x[i]))%3;
            }
        }
    }
    if(x[m+1]!=0)return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)pt[i][j]=0;
        for(int i=1;i<=m;i++)for(int j=1;j<=m+1;j++)a[i][j]=0;
        bool ok=1;
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b>>c[i];
            pt[a][b]=pt[b][a]=i;
            if(c[i]>0){
                for(int i=1;i<=m+1;i++)x[i]=0;
                x[i]=1;x[m+1]=c[i]-1;
                if(ins()){ok=0;}
            }
        }
        if(!ok)goto e;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++)for(int k=1;k<j;k++){
                if(pt[i][j]&&pt[j][k]&&pt[k][i]){
                    for(int i=1;i<=m+1;i++)x[i]=0;
                    x[pt[i][j]]=x[pt[j][k]]=x[pt[k][i]]=1;
                    if(ins()){
                        ok=0;goto e;
                    }

                }
            }
        }
        e:
        if(ok){
            for(int i=m;i>=1;i--){
                for(int j=1;j<i;j++){
                    a[j][m+1]=(a[j][m+1]+(3-a[i][m+1])*a[j][i])%3;
                }
            }
            for(int i=1;i<=m;i++)cout<<a[i][m+1]+1<<' ';
        }else cout<<"-1";
        cout<<'\n';
    }
    return 0;
}