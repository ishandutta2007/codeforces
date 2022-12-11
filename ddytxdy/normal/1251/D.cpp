#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
int t,n,nn;LL S;
struct node{int l,r;bool friend operator <(node a,node b){return a.l>b.l;}}a[N];
bool check(int x){
    int num=0;LL now=0;
    for(int i=1;i<=n;i++)
        if(a[i].r>=x&&num<nn)now+=max(x,a[i].l),num++;
        else now+=a[i].l;
    return num==nn&&now<=S;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%I64d",&n,&S);nn=(n+1)>>1;
        for(int i=1;i<=n;i++)scanf("%d%d",&a[i].l,&a[i].r);
        sort(a+1,a+n+1);
        int l=1,r=1e9,ans;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid))ans=mid,l=mid+1;
            else r=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}