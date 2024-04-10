#include <bits/stdc++.h>
using namespace std;


int n,m;
char ans[105][105];
int x[5][5];
inline void add(int x,int y,int xx,int yy,int zz) {
    char last=('A'+zz-1);
    for (int i=x;i<=x+xx-1;++i)
        for (int j=y;j<=y+yy-1;++j)
            ans[i][j]=last;
}
inline void prnt(int x) {
    cout<<x<<'\n';
    for (int i=1;i<=x;++i) {
        for (int j=1;j<=x;++j)
            cout<<ans[i][j];
        cout<<'\n';
    }
    exit(0);
}

inline void check1(int x,int y,int xx,int yy,int xxx,int yyy,int p1,int p2,int p3) {
    if (x==xx+xxx && yy==yyy && y+yy==x) {
        add(1,1,x,y,p1);
        add(1,y+1,xx,yy,p2);
        add(xx+1,y+1,xxx,yyy,p3);
        prnt(x);
        exit(0);
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=1;i<=3;++i)
        for (int j=0;j<2;++j)
        cin>>x[i][j];
    for (int i=0;i<2;++i)
        for (int j=0;j<2;++j)
    for (int k=0;k<2;++k) {
        if (x[1][i]==x[2][j] && x[2][j]==x[3][k] && x[1][i]==(x[1][1-i]+x[2][1-j]+x[3][1-k])) {
            add(1,1,x[1][i],x[1][1-i],1);
            add(1,x[1][1-i]+1,x[2][j],x[2][1-j],2);
            add(1,x[1][1-i]+x[2][1-j]+1,x[3][k],x[3][1-k],3);
            prnt(x[1][i]);
        }
    }
    for (int i=1;i<=3;++i)
        for (int j=1;j<=3;++j) if (j!=i)
    for (int k=1;k<=3;++k) if (k!=i && k!=j) {
        for (int z=0;z<2;++z)
            for (int zz=0;zz<2;++zz)
                for (int zzz=0;zzz<2;++zzz) {
                    check1(x[i][z],x[i][1-z],x[j][zz],x[j][1-zz],x[k][zzz],x[k][1-zzz],i,j,k);
                }
    }
    cout<<"-1";
}