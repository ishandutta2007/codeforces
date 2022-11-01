#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int N=1000001;
    char a[N],b[N];
    scanf("%s%s",a,b);
    int n=strlen(a);
    int m=strlen(b);
    int ca=0,cb=0;
    while(ca<n&&a[ca]=='0') ca++;
    while(cb<m&&b[cb]=='0') cb++;
    int la=n-ca,lb=m-cb;
    if(la<lb) printf("<\n");
    else if(la>lb) printf(">\n");
    else
    {
        for(int i=0;i<la;i++)
        {
            if(a[ca+i]<b[cb+i])
            {
                printf("<\n");
                return 0;
            }
            if(a[ca+i]>b[cb+i])
            {
                printf(">\n");
                return 0;
            }
        }
        printf("=\n");
    }
    return 0;
}