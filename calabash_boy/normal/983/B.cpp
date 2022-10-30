#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3+100;
int a[maxn];
int ans[maxn][maxn];
int n,q;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for (int i=1;i<=n;i++){
        ans[i][1]=a[i];
    }
    for (int len = 2;len<=n;len++){
        for (int i=1;i<=n-len+1;i++){
            ans[i][len] = ans[i][len-1]^ans[i+1][len-1];
        }
    }
    for (int len=2;len<=n;len++){
        for (int i=1;i<=n-len+1;i++){
            ans[i][len] = max(max(ans[i][len],ans[i][len-1]),ans[i+1][len-1]);
        }
    }
    scanf("%d",&q);
    while (q--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",ans[l][r-l+1]);
    }
    return 0;
}