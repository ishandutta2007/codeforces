#include <stdio.h>
#include <string.h>
char a[110],b[110],c[110],d[110];
int main(){
scanf("%s",a);
scanf("%s",b);
scanf("%s",c);
scanf("%s",d);
int l,p,j,k,kl;
l=strlen(a)-2;
p=strlen(b)-2;
j=strlen(c)-2;
k=strlen(d)-2;kl=0;
if(l>=p+p&&l>=j+j&&l>=k+k)kl++;
if(2*l<=p&&2*l<=j&&2*l<=k)kl++;
if(2*p<=l&&2*p<=j&&2*p<=k)kl++;
if(p>=l+l&&p>=j+j&&p>=k+k)kl++;
if(2*k<=l&&2*k<=j&&2*k<=p)kl++;
if(k>=l+l&&k>=j+j&&k>=p+p)kl++;
if(2*j<=l&&2*j<=k&&2*j<=p)kl++;
if(j>=l+l&&j>=k+k&&j>=p+p)kl++;
if (kl!=1){printf("C");return 0;}
if(l>=p+p&&l>=j+j&&l>=k+k){printf("A");return 0;}
if(2*l<=p&&2*l<=j&&2*l<=k){printf("A");return 0;}
if(2*p<=l&&2*p<=j&&2*p<=k){printf("B");return 0;}
if(p>=l+l&&p>=j+j&&p>=k+k){printf("B");return 0;}
if(2*k<=l&&2*k<=j&&2*k<=p){printf("D");return 0;}
if(k>=l+l&&k>=j+j&&k>=p+p){printf("D");return 0;}
printf("C");
return 0;
}