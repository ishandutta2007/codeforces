#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=220;
int T,n,m;bool flag;
struct node{int t,l,r;bool friend operator <(node a,node b){return a.t<b.t;}}a[N];
void solve(){
    scanf("%d%d",&n,&m);flag=1;
    for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].t,&a[i].l,&a[i].r);
    sort(a+1,a+n+1);a[0].l=a[0].r=m;
    for(int i=1;i<=n;i++)
        a[i].l=max(a[i].l,a[i-1].l-a[i].t+a[i-1].t),
        a[i].r=min(a[i].r,a[i-1].r+a[i].t-a[i-1].t);
    for(int i=n-1;i;i--)
        a[i].l=max(a[i].l,a[i+1].l+a[i].t-a[i+1].t),
        a[i].r=min(a[i].r,a[i+1].r-a[i].t+a[i+1].t);
    for(int i=1;i<=n;i++)if(a[i].l>a[i].r)flag=0;
    puts(flag?"YES":"NO");
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}