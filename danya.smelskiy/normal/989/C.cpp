#include <bits/stdc++.h>
using namespace std;


int a[5];
char ans[51][51];

inline void clr(int x,int y,int xx,int yy,char c) {
    for (int i=x;i<=xx;++i)
        for (int j=y;j<=yy;++j)
            ans[i][j]=c;
}

inline void clr2(int x,int y,int xx,int yy,char c,int z) {
    for (int i=x+1;i<=xx;i+=2) {
        for (int j=y+1;j<=yy;j+=2) {
            if (!z) return;
            ans[i][j]=c;
            --z;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=0;i<4;++i)
        cin>>a[i],--a[i];
    clr(1,1,25,25,'A');
    clr(1,26,25,50,'B');
    clr(26,1,50,25,'C');
    clr(26,26,50,50,'D');
    clr2(1,1,25,25,'B',a[1]);
    clr2(1,26,25,50,'C',a[2]);
    clr2(26,1,50,25,'D',a[3]);
    clr2(26,26,50,50,'A',a[0]);
    cout<<50<<" "<<50<<'\n';
    for (int i=1;i<=50;++i) {
        for (int j=1;j<=50;++j)
            cout<<ans[i][j];
        cout<<'\n';
    }
}