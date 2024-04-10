#include <stdio.h>
int main(){
 int n,t;
 scanf("%d %d",&n,&t);
 char a[n+2],c;
 scanf("%s",a);
 while(t-->0){
  for(int i=0;i<n-1;i++){
   if(a[i]=='B'&&a[i+1]=='G'){
    c=a[i];
    a[i]=a[i+1];
    a[i+1]=c;
    i++;
   }
  }
 }
 printf("%s",a);
}