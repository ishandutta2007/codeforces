#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
int a[200005];
int mx[200005][20];
int query(int l,int r){
    int len=r-l+1,p=log2(len);
    return max(mx[l][p],mx[r-(1<<p)+1][p]);
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,m,q;
        cin>>n>>m;
        for(int i=1;i<=m;i++) scanf("%d",&a[i]),mx[i][0]=a[i];
        for(int i=1;i<20;i++)
            for(int j=1;j<=m;j++)
                mx[j][i]=max(mx[j][i-1],mx[min(m,j+(1<<(i-1)))][i-1]);
        cin>>q;
        for(int i=1;i<=q;i++){
            int xs,ys,xe,ye,k;
            scanf("%d%d%d%d%d",&xs,&ys,&xe,&ye,&k);
            if(abs(xs-xe)%k||abs(ys-ye)%k){
                puts("NO");
                continue;
            }
            int d=(n-xs)/k,v=xs+d*k;
            int e=query(min(ys,ye),max(ys,ye));
            if(e<v) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
//unordered_map
//cf