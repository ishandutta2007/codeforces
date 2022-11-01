#include <cstdio>
int a[5000001],l,r,b,p=1;
char s[5000002];

int main()
{
    gets(s+1);
    for(int i=1;s[i];i++)
    {
        l=3*l+s[i];
        r+=p*s[i];
        p*=3;
        a[i]=(l==r)*(a[i/2]+1);
        b+=a[i];
    }
    printf("%d\n",b);
    return 0;
}