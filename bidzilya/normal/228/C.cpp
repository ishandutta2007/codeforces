#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long ll;
const int MAX_INT = 1e9;

int n,m;
int a[500][500];
int sm[500][500];
int obr[2][2];
bool an[500][500][9][16];
bool fnd[500][500][9][16];
int hobr;

bool sum(int ly,int lx,int ry,int rx){
    int tmp = sm[ry][rx];
    if (ly>0)tmp -= sm[ly-1][rx];
    if (lx>0)tmp -= sm[ry][lx-1];
    if (lx>0 && ly>0)tmp += sm[ly-1][lx-1];
    return (tmp==((ry-ly+1)*(rx-lx+1)));
}

bool check(int sy,int sx,int slen){
     bool & ff = fnd[sy][sx][slen][hobr];
     bool & aa = an[sy][sx][slen][hobr];
     if (ff)
        return aa;
     ff = true;
     if (slen==1){
        aa = (a[sy][sx]==obr[0][0] && a[sy][sx+1]==obr[0][1] &&
                a[sy+1][sx]==obr[1][0] && a[sy+1][sx+1]==obr[1][1]);
        return aa;
     }
     int len = (1<<slen);
     int lle = len/2;
     aa = true;
     for (int i=0;i<2;i++)
         for (int j=0;j<2;j++)
             if (obr[i][j]==0)
                aa = aa && check(sy+lle*i,sx+lle*j,slen-1);
             else
                 aa = aa && sum(sy+lle*i,sx+lle*j,sy+lle*i+lle-1,sx+lle*j+lle-1);
     return aa;
}

bool fract(int sy,int sx,int slen){
     int len = (1<<slen);
     int lle = len/2;
     obr[0][0]=sum(sy,sx,sy+lle-1,sx+lle-1);
     obr[0][1]=sum(sy,sx+lle,sy+lle-1,sx+len-1);
     obr[1][0]=sum(sy+lle,sx,sy+len-1,sx+lle-1);
     obr[1][1]=sum(sy+lle,sx+lle,sy+len-1,sx+len-1);
     hobr = obr[0][0]+obr[0][1]*2+obr[1][0]*4+obr[1][1]*8;
     return check(sy,sx,slen);
}

int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            char c;
            cin >> c;
            if (c=='.')
               a[i][j]=0;
            else
                a[i][j]=1;
        }
    sm[0][0]=a[0][0];
    for (int i=1;i<m;i++)sm[0][i]=sm[0][i-1]+a[0][i];
    for (int i=1;i<n;i++)sm[i][0]=sm[i-1][0]+a[i][0];
    for (int i=1;i<n;i++)
        for (int j=1;j<m;j++)
            sm[i][j]=sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1]+a[i][j];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            for (int t=0;t<9;t++)
                for (int k=0;k<16;k++)
                    fnd[i][j][t][k]=false;
    int ans = 0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            for (int slen=2,len=4;i+len<=n && j+len<=m;len *=2,slen++)
                ans += fract(i,j,slen);
    cout << ans << endl;
    return 0;
}