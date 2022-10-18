#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int mdn=998244353;
const int maxn=1005;
const int sz=26;

int n,m;
char a[maxn],b[maxn];
int f[maxn][maxn][2];
int ra[maxn],rb[maxn];

int main(){
    cin>>(a+1)>>(b+1);
    n=strlen(a+1);m=strlen(b+1);
    ra[1]=rb[1]=1;
    for(int i=2;i<=n;i++)ra[i]=1+(a[i]!=a[i-1]?ra[i-1]:0);
    for(int i=2;i<=m;i++)rb[i]=1+(b[i]!=b[i-1]?rb[i-1]:0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j][0]=(a[i]!=b[j]?rb[j]:0)+(a[i]!=a[i-1]?f[i-1][j][0]:0)+(a[i]!=b[j]?f[i-1][j][1]:0);
            f[i][j][1]=(a[i]!=b[j]?ra[i]:0)+(b[j]!=a[i]?f[i][j-1][0]:0)+(b[j]!=b[j-1]?f[i][j-1][1]:0);
            f[i][j][0]%=mdn;
            f[i][j][1]%=mdn;
        }
    }
    long long tot=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)tot+=f[i][j][0]+f[i][j][1];
    cout<<tot%mdn;
    return 0;
}