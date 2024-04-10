#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int t,n,b[N],ans,dat;
struct node{int l,r;bool friend operator <(node a,node b){return a.l<b.l;}}a[N];
vector<int>p;
int read(){
    int x=0,c,f=1;
    while(!isdigit(c=getchar()))c=='-'?f=-1:0;
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x*f;
}
void solve(){
    n=read();ans=0;dat=-1;
    for(int i=1;i<=n;i++)a[i].l=read(),a[i].r=read();
    sort(a+1,a+n+1);
    for(int i=1,mx=-1,mx2=-1;i<=n;i++){
        if(mx==-1||a[mx].r<a[i].l)ans++,b[i]=-1;
        else{
            b[i]=0;
            if(mx2==-1||a[mx2].r<a[i].l)b[mx]++;
        }
        int x=i;
        if(mx==-1||a[mx].r<a[x].r)swap(x,mx);
        if(x!=-1&&(mx2==-1||a[mx2].r<a[x].r))mx2=x;
    }
    for(int i=1;i<=n;i++)dat=max(dat,b[i]);
    printf("%d\n",ans+dat);
}
int main(){
    t=read();
    while(t--)solve();
    return 0;
}