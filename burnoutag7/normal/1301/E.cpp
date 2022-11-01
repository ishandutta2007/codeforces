#include<bits/stdc++.h>
using namespace std;

int n,m,q;
char g[505][505];
int pR[505][505];
int pG[505][505];
int pB[505][505];
int pY[505][505];

//===========================~~==============================
const int maxn=505;
int mm[maxn<<1];
int val[maxn][maxn];
int dpmin[maxn][maxn][10][10];
int dpmax[maxn][maxn][10][10];
void initRMQ(int n,int m)
{
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        dpmin[i][j][0][0]=dpmax[i][j][0][0]=val[i][j];
    for(int ii=0;ii<=mm[n];ii++)
    for(int jj=0;jj<=mm[m];jj++)
    if(ii+jj)
    for(int i=1;i+(1<<ii)-1<=n;i++)
    for(int j=1;j+(1<<jj)-1<=m;j++)
    {
        if(ii)
        {
            dpmin[i][j][ii][jj] = min(dpmin[i][j][ii-1][jj],dpmin[i+(1<<(ii-1))][j][ii-1][jj]);
            dpmax[i][j][ii][jj] = max(dpmax[i][j][ii-1][jj],dpmax[i+(1<<(ii-1))][j][ii-1][jj]);
        }
        else
        {
            dpmin[i][j][ii][jj] = min(dpmin[i][j][ii][jj-1],dpmin[i][j+(1<<(jj-1))][ii][jj-1]);
            dpmax[i][j][ii][jj] = max(dpmax[i][j][ii][jj-1],dpmax[i][j+(1<<(jj-1))][ii][jj-1]);
        }
    }
}
int rmxq(int x1,int y1,int x2,int y2)  //max
{
    int k1=mm[x2-x1+1];
    int k2=mm[y2-y1+1];
    x2=x2-(1<<k1)+1;
    y2=y2-(1<<k2)+1;
    return max(max(dpmax[x1][y1][k1][k2],dpmax[x1][y2][k1][k2]),max(dpmax[x2][y1][k1][k2],dpmax[x2][y2][k1][k2]));
}
int rmnq(int x1,int y1,int x2,int y2)
{
    int k1=mm[x2-x1+1];
    int k2=mm[y2-y1+1];
    x2=x2-(1<<k1)+1;
    y2=y2-(1<<k2)+1;
    return min(min(dpmin[x1][y1][k1][k2],dpmin[x1][y2][k1][k2]),min(dpmin[x2][y1][k1][k2],dpmin[x2][y2][k1][k2]));
}
void initmm()
{
    mm[0]=-1;
    for(int i=1;i<=1000;i++)
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
}
//=============================~~===================

bool check(int x,int y,int s){
    if(!(x-s>=0&&y-s>=0&&x+s<=n&&y+s<=m))return false;
    if(pR[x-s][y-s]+pR[x][y]-pR[x-s][y]-pR[x][y-s]!=s*s)return false;
    if(pG[x-s][y]+pG[x][y+s]-pG[x-s][y+s]-pG[x][y]!=s*s)return false;
    if(pY[x][y-s]+pY[x+s][y]-pY[x][y]-pY[x+s][y-s]!=s*s)return false;
    if(pB[x][y]+pB[x+s][y+s]-pB[x][y+s]-pB[x+s][y]!=s*s)return false;
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initmm();
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>g[i]+1;
        for(int j=1;j<=m;j++){
            pR[i][j]=pR[i-1][j]+pR[i][j-1]-pR[i-1][j-1]+(g[i][j]=='R');
            pG[i][j]=pG[i-1][j]+pG[i][j-1]-pG[i-1][j-1]+(g[i][j]=='G');
            pB[i][j]=pB[i-1][j]+pB[i][j-1]-pB[i-1][j-1]+(g[i][j]=='B');
            pY[i][j]=pY[i-1][j]+pY[i][j-1]-pY[i-1][j-1]+(g[i][j]=='Y');
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int cur=0;
            while(check(i,j,cur+1))cur++;
            val[i][j]=4*cur*cur;
        }
    }
    initRMQ(n,m);
    while(q--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        int l=0,r=min(r2-r1+1,c2-c1+1)/2,m,res;
        while(l<=r){
            m=(l+r)>>1;
            if(rmxq(r1+m-1,c1+m-1,r2-m,c2-m)>=4*m*m){
                res=m;
                l=m+1;
            }else{
                r=m-1;
            }
        }
        cout<<4*res*res<<'\n';
    }

    return 0;
}