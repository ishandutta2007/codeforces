#include <bits/stdc++.h>
using namespace std;


long long n,q,c;
long long x,y,z;
long long kol[150][150][15];
long long t,xx,yy;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q>>c;
    for (int i=1;i<=n;++i) {
        cin>>x>>y>>z;
        ++kol[x][y][z];
    }
    for (int i=1;i<=100;++i){
        for (int j=1;j<=100;++j) {
            for (int k=0;k<=c;++k) {
                kol[i][j][k]=kol[i][j][k]-kol[i-1][j-1][k]+kol[i-1][j][k]+kol[i][j-1][k];
            }
        }
    }
    for (int i=1;i<=q;++i) {
        cin>>t>>x>>y>>xx>>yy;
        t%=(c+1);
        if (x>xx) swap(x,xx);
        if (y>yy) swap(y,yy);
        long long res=0;
        for (int j=0;j<=c;++j) {
            long long now=kol[xx][yy][j]+kol[x-1][y-1][j]-kol[x-1][yy][j]-kol[xx][y-1][j];
            long long z=j;
            for (int k=1;k<=t;++k){
                if (z==c) z=-1;
                ++z;
            }
            res+=now*z;
        }
        cout<<res<<'\n';
    }
}