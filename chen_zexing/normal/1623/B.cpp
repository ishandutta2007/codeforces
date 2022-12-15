#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <string.h>
using namespace std;
int l[1005],r[1005],f[1005];
int valid[1005][1005];
void solve(int l,int r){
    if(l>r) return;
    for(int i=l-1;i<r;i++)
        if(valid[l][i]&&valid[i+2][r]) {
            printf("%d %d %d\n",l,r,i+1);
            solve(l, i), solve(i + 2, r);
        }
}
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                valid[i][j]=0;
        for(int i=1;i<=n+1;i++) valid[i][i-1]=1;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&l[i],&r[i]),f[i]=0;
            valid[l[i]][r[i]]=1;
        }
        solve(1,n);
    }
    return 0;
}