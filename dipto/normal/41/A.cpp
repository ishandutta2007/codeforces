#include<cstdio>
#include<cstring>

int main()
{
char a[1000],b[1000];
int i,j;
gets(a);
gets(b);
int n,flag=1;
if((n=strlen(a))==strlen(b))
                           {
                           //printf("%d\n",n);
                            for(i=0;i<n;i++)
                            if(a[i]!=b[n-1-i])
                            flag=0;}
else flag=0;
if(flag==1) printf("YES\n");
else printf("NO\n");
//gets(b);
return 0;
}