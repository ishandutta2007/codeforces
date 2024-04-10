#include<bits/stdc++.h>
using namespace std;
int T,n,L[100010],R[100010],C[100010];
void solve(){
    scanf("%d",&n);
    int minL=2e9,minvL=0,maxR=0,minvR=0,maxL=0,minv=0;
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&L[i],&R[i],&C[i]);
        if(R[i]-L[i]+1==maxL) minv=min(minv,C[i]);
        else if(R[i]-L[i]+1>maxL) maxL=R[i]-L[i]+1,minv=C[i];
        if(L[i]==minL) minvL=min(minvL,C[i]);
        else if(L[i]<minL) minL=L[i],minvL=C[i];
        if(R[i]==maxR) minvR=min(minvR,C[i]);
        else if(R[i]>maxR) maxR=R[i],minvR=C[i];
        int ans=minvL+minvR;
        if(maxR-minL+1==maxL) ans=min(ans,minv);
        printf("%d\n",ans);
    }
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}