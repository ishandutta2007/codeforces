/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-04-15 23:13:05
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int T,na,nb,nc,a[100010],b[100010],c[100010];
long long ans;
void upt(int x,int y,int z){
    if(x<1||x>na||y<1||y>nb||z<1||z>nc) return;
    x=a[x];y=b[y];z=c[z];
    long long p=x-y,q=y-z,r=z-x;
    ans=min(ans,p*p+q*q+r*r);
}
int bef(int *a,int n,int x){return lower_bound(a+1,a+n+1,x)-a;}
int nxt(int *a,int n,int x){return upper_bound(a+1,a+n+1,x)-a-1;}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&na,&nb,&nc);
        for(int i=1;i<=na;i++) scanf("%d",&a[i]);
        for(int i=1;i<=nb;i++) scanf("%d",&b[i]);
        for(int i=1;i<=nc;i++) scanf("%d",&c[i]);
        sort(a+1,a+na+1);sort(b+1,b+nb+1);sort(c+1,c+nc+1);
        ans=5e18;
        for(int i=1;i<=na;i++){
            int bp[2]={bef(b,nb,a[i]),nxt(b,nb,a[i])},cp[2]={bef(c,nc,a[i]),nxt(c,nc,a[i])};
            upt(i,bp[0],bef(c,nc,(a[i]+b[bp[0]])/2));
            upt(i,bp[0],nxt(c,nc,(a[i]+b[bp[0]])/2));
            upt(i,bp[1],bef(c,nc,(a[i]+b[bp[1]])/2));
            upt(i,bp[1],nxt(c,nc,(a[i]+b[bp[1]])/2));
            upt(i,bef(b,nb,(a[i]+c[cp[0]])/2),cp[0]);
            upt(i,nxt(b,nb,(a[i]+c[cp[0]])/2),cp[0]);
            upt(i,bef(b,nb,(a[i]+c[cp[1]])/2),cp[1]);
            upt(i,nxt(b,nb,(a[i]+c[cp[1]])/2),cp[1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}