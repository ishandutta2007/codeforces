#include<stdio.h>
#include<stdlib.h>
bool used[10];
main(){
    int i,j,a,b,x,d[99],m=0;
    char s1[8],s2[8];
    scanf("%s%s",s1,s2);
    for(i=0;s1[i];i++)
        used[s1[i]-'0']=1;
    for(i=0;s2[i];i++)
        used[s2[i]-'0']=1;
    for(i=9;i>0;i--)
        if(used[i])break;
    i++;
    a=atoi(s1);
    b=atoi(s2);
    while(a+b){
        d[m++]=a%10+b%10;
        a/=10;
        b/=10;
    }
    d[m]=0;
    for(j=0;j<m;j++){
        d[j+1]+=d[j]/i;
    }
    if(d[m]==0)printf("%d\n",m);
    else{
        while(d[m]>=i){
            d[m+1]=d[m]/i;
            m++;
        }
        printf("%d\n",m+1);
    }
    
}