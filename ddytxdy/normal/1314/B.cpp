#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,k,m,a[N];
void cmax(int &x,int y){y>x?x=y:0;}
struct node{
    int d[4];
    void init(){memset(d,0xcf,sizeof(d));}
    node friend operator +(node a,node b){
        node c;c.init();
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                int x=i>>1,y=i&1,z=j>>1,w=j&1;
                cmax(c.d[(x<<1)+(z|y|w)],a.d[i]+b.d[j]+(x|z)+(y|w)+(z|y|w));
                cmax(c.d[(z<<1)+(x|y|w)],a.d[i]+b.d[j]+(x|z)+(y|w)+(x|y|w));
            }
        return c;
    }
}t[N*4];
void solve(int x,int l,int r){
    if(r-l==1){
        t[x].init();
        if(a[l]&&a[r])t[x].d[3]=1;
        else if(!a[l]&&!a[r])t[x].d[0]=0;
        else t[x].d[1]=t[x].d[2]=1;
        return;
    }
    int mid=(l+r)>>1;
    solve(x<<1,l,mid);solve(x<<1|1,mid+1,r);
    t[x]=t[x<<1]+t[x<<1|1];
}
int main(){
    scanf("%d%d",&n,&k);m=1<<n;
    for(int i=1,x;i<=k;i++)scanf("%d",&x),a[x]=1;
    solve(1,1,m);cout<<max(t[1].d[0],max(t[1].d[1]+1,max(t[1].d[2]+1,t[1].d[3]+1)));
    return 0;
}