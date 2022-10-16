//  228

#include <stdio.h>
int main()
{
    int x1,x2,i,j,n;
    int a[100000+10];
    scanf("%d",&n);
      for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    x1=x2=0;
      for(i=0,j=n-1;i<=j;)
      {  if(x1<=x2)
           x1+=a[i],i++;
           else x2+=a[j--];

      }
      printf("%d %d",i,n-i);
}