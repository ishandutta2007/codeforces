#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,q,a[N],r[N],num[N],ans;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        r[a[i]]=i;
    }
    for(int i=1,rr,j,mx;i<=n;i++){
        for(j=i,rr=i,mx=0;j<=rr;j++){
            num[a[j]]++;rr=max(rr,r[a[j]]);
            mx=max(mx,num[a[j]]);
        }j--;
        ans+=j-i+1-mx;
        i=j;
    }
    printf("%d\n",ans);
    return 0;
}