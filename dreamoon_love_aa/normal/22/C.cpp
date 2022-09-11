#include<stdio.h>
int a[100001],b[100001];
main(){
    int n,m,v,k,i,j,ii;
    scanf("%d%d%d",&n,&m,&v);
    for(i=1,k=0;k<1;i++)
        if(i!=v)a[k++]=i;
    if(m<n-1||m>k*(k+1)/2+(n-k)*(n-k-1)/2)puts("-1");
    else{
        a[k]=v;
        for(ii=0,j=i;j<=n;j++)
            if(j!=v)b[ii++]=j;
        for(i=0;i<k;i++)printf("%d %d\n",a[i],a[i+1]);
        b[ii]=v;
        for(j=0;j<ii;j++)printf("%d %d\n",b[j],b[j+1]);
        m-=n-1;
        for(i=0;i<k&&m>0;i++)
            for(j=i+2;j<=k&&m>0;j++){
                printf("%d %d\n",a[i],a[j]);
                m--;
            }
        for(i=0;i<ii&&m>0;i++)
            for(j=i+2;j<=ii&&m>0;j++){
                printf("%d %d\n",b[i],b[j]);
                m--;
            }
    }
}