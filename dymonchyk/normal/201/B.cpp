#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int x[1002],y[1002];
unsigned long long vx[1002],vy[1002],tmp=1;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;++j) {
            scanf("%d",&a);
            x[i]+=a; y[j]+=a;
        }
    int bx=-1,by; unsigned long long ans;
    for(int cx=0;cx<=n;++cx) {
        vx[cx]=0;
        for(int i=0;i<=n;++i)
            vx[cx]+=tmp*x[i]*(4*cx-(4*i+2))*(4*cx-(4*i+2));
    }
    for(int cy=0;cy<=m;++cy) {
        vy[cy]=0;
        for(int i=0;i<=m;++i)
            vy[cy]+=tmp*y[i]*(4*cy-(4*i+2))*(4*cy-(4*i+2));
    }
    for(int i=0;i<=n;++i)
        for(int j=0;j<=m;++j)
            if (bx==-1||ans>vx[i]+vy[j]) {bx=i; by=j; ans=vx[i]+vy[j];}
    cout << ans << endl;
    printf("%d %d\n",bx,by);
    return 0;
}