#include<stdio.h>
int a[100000];
bool Go(int b[],int n){
    int i;
    if(b[0]==0){
        for(i=1;i<n;i++)
            if(b[i])break;
        return i>=n;
    }
    for(i=2;i<n;i++)
        if(b[i-1]*b[1]!=b[0]*b[i])break;
    return i>=n;
}
void One(int n){
    int m,b[24],i,j;
    for(i=0;i<n;i++){
        m=0;
        for(j=0;j<n;j++){
            if(i==j)continue;
            b[m++]=a[j];
        }
        if(Go(b,m)){
            puts("1");
            break;
        }
    }
    if(i==n)puts("2");
}
main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    if(n<20){
        if(a[0]==0){
            for(i=1;i<n;i++)
                if(a[i])break;
            if(i>=n)puts("0");
            else One(n);
        }
        else{
            for(i=2;i<n;i++)
                if(a[i-1]*a[1]!=a[0]*a[i])break;
            if(i>=n)puts("0");
            else One(n);
        }
    }
    else{
        if(a[0]==0){
            j=0;
            for(i=1;i<n;i++)
                if(a[i])j++;
            if(j==0)puts("0");
            else if(j==1)puts("1");
            else if(Go(a+1,n-1))puts("1");
            else puts("2");
        }
        else{
            int zero=0,k=0;
            j=0;
            for(i=1;i<n;i++){
                if(a[i]!=a[0])j++;
                if(a[i])zero++;
                if((i+k)&1){
                    if(a[i]!=-a[0])k++;
                }
                else{
                    if(a[i]!=a[0])k++;
                }
            }
            if(j==0||zero==0||k==0)puts("0");
            else if(j==1||zero==1||k==1)puts("1");
            else if(Go(a+1,n-1))puts("1");
            else puts("2");
        }
    }
}