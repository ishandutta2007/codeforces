#include<bits/stdc++.h>
using namespace std;
int T,n,C[510][510];
void solve(){long long sum=0;
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=2*n;j++){
            scanf("%d",&C[i][j]);
            if(i>n&&j>n) sum+=C[i][j];
        }
    }
    printf("%lld\n",sum+min(min(min(min(C[n][n+1],C[n+1][n]),min(C[n][2*n],C[2*n][n])),min(C[1][n+1],C[n+1][1])),min(C[1][2*n],C[2*n][1])));
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}