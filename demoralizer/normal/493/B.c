#include<stdio.h>
int main(){
    long long int n,l,lg=0,t,s=0,w=0;
    scanf("%I64d",&n);
    long long int a[n],b[n],c=0,d=0;
    for(long long int i=0;i<n;i++){
        scanf("%I64d",&t);
        s+=t;
        if(t>0){l=1;a[c]=t;c++;} else {l=2;b[d]=-t;d++;}
    }
    if(s>0)w=1;else if(s<0)w=2;
    if(w==0){
        long long int m=c<d?c:d;
        for(long long int i=0;i<m;i++){
            if(a[i]>b[i]){w=1;break;}
            if(a[i]<b[i]){w=2;break;}
        }
    }
    if(w==0)w=l;
    if(w==1)printf("first");
    else printf("second");
}