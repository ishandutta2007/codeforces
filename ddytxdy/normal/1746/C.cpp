#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+50;
const double eps=1e-12;
int n,T,a[N],cnt,c[N];
struct node{
    int x,diff;
    bool friend operator <(node a,node b){
        return a.diff>b.diff;
    }
}b[N];
void solve(){
    scanf("%d",&n);cnt=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),c[i]=0;
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1])b[++cnt]=(node){i,a[i-1]-a[i]};
    }
    sort(b+1,b+cnt+1);
    for(int i=1;i<=cnt;i++){
        c[n-i+1]=b[i].x;
    }
    for(int i=1;i<=n;i++)
        if(!c[i])c[i]=1;
    for(int i=1;i<=n;i++)
        printf("%d ",c[i]);
    puts("");
}
int main(){
    // freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}