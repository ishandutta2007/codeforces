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
vector <int> v[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) v[i].resize(m+5);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&v[i][j]);
        int ll=m+1,rr=0;
        for(int i=1;i<=n;i++){
            int mx=0,r=0,l=m+1,mn=INT_MAX;
            for(int j=1;j<=m;j++){
                if(mx>v[i][j]) r=j;
                mx=max(mx,v[i][j]);
            }
            for(int j=m;j;j--){
                if(mn<v[i][j]) l=j;
                mn=min(mn,v[i][j]);
            }
            ll=min(ll,l),rr=max(rr,r);
        }
        if(ll==m+1){
            puts("1 1");
            continue;
        }
        int fl=1;
        for(int i=1;i<=n;i++){
            swap(v[i][ll],v[i][rr]);
            for(int j=1;j<=m;j++) if(v[i][j]<v[i][j-1]) fl=0;
        }
        if(fl) printf("%d %d\n",ll,rr);
        else puts("-1");
    }
    return 0;
}
//unordered_map
//cf