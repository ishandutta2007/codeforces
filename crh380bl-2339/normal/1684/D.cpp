#include<bits/stdc++.h>
using namespace std;
int a[200005];bool bo[200005];
struct node{
    int id,val;
}b[200005];
bool cmp(node x,node y){
    return x.val>y.val;
}
void work(){
    int n,i,k;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i){
        bo[i]=0;
        scanf("%d",&a[i]);
        b[i].id=i;
        b[i].val=a[i]+i;
    }
    sort(b+1,b+1+n,cmp);
    for(i=1;i<=k;++i){
        bo[b[i].id]=1;
    }
    int d=0;long long ans=0;
    for(i=1;i<=n;++i){
        if(bo[i]){
            ++d;
        }
        else ans=ans+d+a[i];
    }
    printf("%lld\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}