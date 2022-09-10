#include<stdio.h>
long long n,i,k,nu,a[200001],b[200001],c[200001],ma,mi,st,ed;
void g(long long x,long long y,long long z){
    int mid=(x+y)/2,ii,jj,kk;
    if(x>=y)return;
    g(x,mid,z);
    g(mid+1,y,z);
    for(ii=x;ii<=y;ii++)c[ii]=b[ii];
    for(ii=x,jj=mid+1;ii<=mid;ii++){
        while(jj<=y&&c[jj]<c[ii]+z)jj++;
        nu+=y-jj+1;
    }
    //printf("%I64d %I64d %I64d\n",x,y,nu);
    for(ii=kk=x,jj=mid+1;;){
        if(ii>mid){
            while(jj<=y)b[kk++]=c[jj++];
            break;
        }
        else if(jj>y){
            while(ii<=mid)b[kk++]=c[ii++];
            break;
        }
        else if(c[jj]<c[ii])
            b[kk++]=c[jj++];
        else b[kk++]=c[ii++];
    }
}
bool f(long long x){
    int ii;
    nu=0;
    for(ii=0;ii<=n;ii++)b[ii]=a[ii];
    g(0,n,x);
    if(nu<k)return 1;
    return 0;
}
main(){
    long long an;
    while(scanf("%I64d %I64d",&n,&k)==2&&n+k){
        for(i=1,mi=ma=0,st=10000000000000000ll,ed=-10000000000000000ll;i<=n;i++){
            scanf("%I64d",&a[i]);
            a[i]+=a[i-1];
            if(st>a[i]-ma)st=a[i]-ma;
            if(ed<a[i]-mi)ed=a[i]-mi;
            if(a[i]>ma)ma=a[i];
            if(a[i]<mi)mi=a[i];
        }
        while(st<=ed){
            //printf("%I64d %I64d\n",st,ed);
            if(f((st+ed)/2)==0)an=(st+ed)/2,st=(st+ed)/2+1;
            else ed=(st+ed)/2-1;
        }
        printf("%I64d\n",an);
    }
}