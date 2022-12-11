#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
namespace ZBK{
const int N=110,M=1e5,lim=1<<15;
int n,a[N],b[N],c[N],cnt[M];
struct node{
    int dat[N],x;
    bool friend operator <(node a,node b){
        for(int i=1;i<=n;i++)if(a.dat[i]!=b.dat[i])return a.dat[i]<b.dat[i];
        return 0;
    }
}t1[M],t2[M];
void main(){
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++)scanf("%d",&x),b[i]=x>>15,c[i]=x&(lim-1);
    for(int i=1;i<lim;i++)cnt[i]=cnt[i>>1]+(i&1);
    for(int i=0;i<lim;i++){
        int mn=1e9,mx=0;
        for(int j=1;j<=n;j++)mn=min(mn,cnt[b[j]^i]),mx=max(mx,cnt[c[j]^i]);
        for(int j=1;j<=n;j++)t1[i].dat[j]=cnt[b[j]^i]-mn,t2[i].dat[j]=mx-cnt[c[j]^i];
        t1[i].x=t2[i].x=i;
    }
    sort(t1,t1+lim);sort(t2,t2+lim);
    for(int i=0,j=0;i<lim;i++){
        while(j<lim&&t2[j]<t1[i])j++;
        if(!(t2[j]<t1[i])&&!(t1[i]<t2[j]))printf("%d\n",t1[i].x<<15^t2[j].x),exit(0);
    }
    puts("-1");
}
}
int main(){ZBK::main();return 0;}