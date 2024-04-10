#include<stdio.h>
int max(int a,int b){
return a>b?a:b;
}
int main(){
    int n,l,t,m;
    scanf("%d %d",&n,&l);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(a[j]>a[j+1]){
                t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
            }
    m=max(2*a[0],2*(l-a[n-1]));
    for(int i=1;i<n;i++){
        m=max(m,a[i]-a[i-1]);
    }
    printf("%d",m/2);
    if(m%2) printf(".5000000000");
}