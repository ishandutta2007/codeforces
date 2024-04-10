#include <stdio.h>
int digit(int,int);
int main() {
    int n,count=0; char num[70000];
    scanf("%d %s",&n,&num);
    int b[n];
  
  for(int j=0;j<n;j++)
{
b[j]=num[j]-'0';
    if(b[j]%2==0)
    {
        count=count+j+1;
    }
}
printf("%d",count);
}