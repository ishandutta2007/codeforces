#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n;
string s[1005];
long double ln[1005][1005],sup[1005][1005],slft[1005][1005],sd1[1005][1005],sd2[1005][1005];
int up[1005][1005],dwn[1005][1005],lft[1005][1005],rg[1005][1005],d1[1005][1005],d2[1005][1005],d3[1005][1005],d4[1005][1005];
int a[1005][1005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        for (int j=1;j<=n;++j){
            a[i][j]=s[i][j-1]-'0';
            ln[i][j]=(a[i][j]==0 ? 0. : log((long double)a[i][j]));
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            sup[i][j]=sup[i-1][j]+ln[i][j];
            slft[i][j]=slft[i][j-1]+ln[i][j];
            sd1[i][j]=sd1[i-1][j-1]+ln[i][j];
            sd2[i][j]=sd2[i-1][j+1]+ln[i][j];
            if (a[i][j]==0) continue;
            up[i][j]=up[i-1][j]+1;
            lft[i][j]=lft[i][j-1]+1;
            d1[i][j]=d1[i-1][j-1]+1;
            d2[i][j]=d2[i-1][j+1]+1;
        }
    }
    for (int i=n;i>0;--i) {
        for (int j=n;j>0;--j) {
            if (a[i][j]==0) continue;
            dwn[i][j]=dwn[i+1][j]+1;
            rg[i][j]=rg[i][j+1]+1;
            d3[i][j]=d3[i+1][j+1]+1;
            d4[i][j]=d4[i+1][j-1]+1;
        }
    }
    long double ans1=0;
    int pos1=1,pos2=1,dir=0;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            int l=min(min(up[i][j],dwn[i][j]),min(lft[i][j],rg[i][j]));
            long double sum1=sup[i+l-1][j]-sup[i-l][j]+slft[i][j+l-1]-slft[i][j-l]-ln[i][j];
            if (sum1>ans1) {
                ans1=sum1;
                pos1=i;
                pos2=j;
                dir=0;
            }
            l=min(min(d1[i][j],d2[i][j]),min(d3[i][j],d4[i][j]));
            sum1=sd1[i+l-1][j+l-1]-sd1[i-l][j-l]+sd2[i+l-1][j-l+1]-sd2[i-l][j+l]-ln[i][j];
            if (sum1>ans1) {
                ans1=sum1;
                pos1=i;
                pos2=j;
                dir=1;
            }
        }
    }
    long long ans=a[pos1][pos2];
    if (dir==0) {
        for (int i=1;i<=n;++i) {
            if (pos1+i>n || pos1-i<1 || !(a[pos1+i][pos2]) || !(a[pos1-i][pos2])) break;
            if (pos2+i>n || pos2-i<1 || !(a[pos1][pos2+i]) || !(a[pos1][pos2-i])) break;
            ans=(ans*a[pos1+i][pos2]*a[pos1-i][pos2]*a[pos1][pos2+i]*a[pos1][pos2-i])%md;
        }
        cout<<ans;
        return 0;
    }
    for (int i=1;i<=n;++i) {
        long long q=(a[pos1+i][pos2+i]*a[pos1-i][pos2-i]*a[pos1-i][pos2+i]*a[pos1+i][pos2-i]);
        if (!q) break;
        ans=(ans*q)%md;
    }
    cout<<ans;
}