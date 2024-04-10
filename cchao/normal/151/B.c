#include <stdio.h>
#include <string.h>
typedef struct man
{
    char name[21];
    int size;
    int taxi;
    int pizza;
    int girl;
}Man;
Man t[100];
int judge(char s[10])
{
    int k;
    char x[6]={s[0],s[1],s[3],s[4],s[6],s[7]};
    for(k=1;k<6;k++){
        if(x[k]!=x[k-1]) break;
    }
    if(k==6) return 1;
    for(k=1;k<6;k++){
        if(x[k]>=x[k-1]) break;
    }
    if(k==6) return 2;
    return 3;
}
int main()
{
    int n;
    scanf("%d",&n);
    int k,j;
    char phone[10];
    int m1,m2,m3;
    m1=m2=m3=0;
    for(k=0;k<n;k++){
        scanf("%d%s",&t[k].size,t[k].name);
        t[k].taxi=t[k].pizza=t[k].girl=0;
        for(j=0;j<t[k].size;j++){
            scanf("%s",phone);

            switch(judge(phone))
            {
                case 1:t[k].taxi++;break;
                case 2:t[k].pizza++;break;
                case 3:t[k].girl++;break;
            }
        }

        if(t[k].taxi>m1) m1=t[k].taxi;
        if(t[k].pizza>m2) m2=t[k].pizza;
        if(t[k].girl>m3) m3=t[k].girl;
    }

    int first=1;
    printf("If you want to call a taxi, you should call: ");
    for(k=0;k<n;k++)
    {
        if(m1==t[k].taxi)
        {
            if(!first) printf(", ");
            else first=0;
            printf("%s",t[k].name);
        }
    }
    printf(".\n");
    printf("If you want to order a pizza, you should call: ");
    first=1;
    for(k=0;k<n;k++)
    {
        if(m2==t[k].pizza)
        {
            if(!first) printf(", ");
            else first=0;
            printf("%s",t[k].name);
        }
    }
    printf(".\n");
    printf("If you want to go to a cafe with a wonderful girl, you should call: ");
    first=1;
    for(k=0;k<n;k++)
    {
        if(m3==t[k].girl)
        {
            if(!first) printf(", ");
            else first=0;
            printf("%s",t[k].name);
        }
    }
    printf(".\n");
    return 0;
}