#include<bits/stdc++.h>
//dengyaotriangle
using namespace std;

const int maxn=100005;
const int maxp=102;

int n,m,p;
long long pfx[maxn];

long long h[maxn],hp[maxn];
long long dp[2][maxn];
int ql,qr;
long long qx[maxn],qy[maxn];

int main(){
    cin>>n>>m>>p;
    for(int i=2;i<=n;i++){cin>>pfx[i];pfx[i]+=pfx[i-1];}    
    for(int i=1;i<=m;i++){
        long long f;
        int id;
        cin>>id>>f;
        h[i]=f-pfx[id];
    }
    sort(h+1,h+1+m);
    for(int i=1;i<=m;i++){
        hp[i]=hp[i-1]+h[i];
        //cout<<h[i]<<endl;
    }
    for(int i=1;i<=m;i++)dp[1][i]=i*h[i]-hp[i];
    for(int i=2;i<=p;i++){
        ql=qr=1;qx[1]=qy[1]=0;
        for(int j=1;j<=m;j++){
            while(ql<qr&&(qy[ql+1]-qy[ql])<=(qx[ql+1]-qx[ql])*h[j])ql++;
            dp[i&1][j]=qy[ql]-qx[ql]*h[j]+j*h[j]-hp[j];
            long long cx=j,cy=hp[j]+dp[(i&1)^1][j];
            while(ql<qr&&(qy[qr]-qy[qr-1])*(cx-qx[qr])>=(qx[qr]-qx[qr-1])*(cy-qy[qr]))qr--;
            qr++;qy[qr]=cy;qx[qr]=cx;
            //cout<<i<<','<<j<<':'<<dp[i&1][j]<<endl;
        }
    }
    cout<<dp[p&1][m];
    return 0;
}