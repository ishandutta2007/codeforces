#include<stdio.h>
int main(){
    int p,q,l,r,z=0;
    scanf("%d %d %d %d",&p,&q,&l,&r);
    int a[p],b[p],c[q],d[q];
    for(int i=0;i<p;i++)
        scanf("%d %d",&a[i],&b[i]);
    for(int i=0;i<q;i++)
        scanf("%d %d",&c[i],&d[i]);
    for(int t=l;t<=r;t++){
        int ao=0,co=0,ac=0,cc=0;
        for(int i=0;i<=1000;i++){
            if(ac<p&&i==a[ac]){ao=1;}
            if(cc<q&&i==(c[cc]+t)){co=1;}
            if(ao&&co){z++;goto agla;}
            if(ao&&i==b[ac]){ao=0;ac++;}
            if(co&&i==(d[cc]+t)){co=0;cc++;}
        }
        agla:;
    }
    printf("%d",z);
}